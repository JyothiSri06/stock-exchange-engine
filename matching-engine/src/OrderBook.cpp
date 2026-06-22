#include "../include/OrderBook.h"
#include <iostream>
#include <ctime>
#include <fstream>
#include "../include/json.hpp"

using json = nlohmann::json;

void OrderBook::addBuyOrder(
    const Order &order)
{
    if (!validateOrder(order))
    {
        return;
    }

    buyOrders.push(order);
    allOrders.emplace(
        order.orderId,
        order);

    orderHistory.push_back(order);
}

void OrderBook::addSellOrder(
    const Order &order)
{
    if (!validateOrder(order))
    {
        return;
    }
    sellOrders.push(order);
    allOrders.emplace(
        order.orderId,
        order);
    orderHistory.push_back(order);
}

Order OrderBook::getBestBuy() const
{
    return buyOrders.top();
}

Order OrderBook::getBestSell() const
{
    return sellOrders.top();
}

void OrderBook::matchOrders()
{
    while (
        !buyOrders.empty() &&
        !sellOrders.empty())
    {

        while (
            !buyOrders.empty() &&
            cancelledOrders.count(
                buyOrders.top().orderId))
        {
            buyOrders.pop();
        }

        while (
            !sellOrders.empty() &&
            cancelledOrders.count(
                sellOrders.top().orderId))
        {
            sellOrders.pop();
        }

        if (
            buyOrders.empty() ||
            sellOrders.empty())
        {
            break;
        }

        Order bestBuy =
            buyOrders.top();

        Order bestSell =
            sellOrders.top();

        if (bestBuy.price < bestSell.price)
        {
            break;
        }

        int tradeQty =
            std::min(
                bestBuy.quantity,
                bestSell.quantity);

        std::time_t now = std::time(nullptr);
        std::string timestamp = std::ctime(&now);

        Trade trade(
            bestBuy.userId,
            bestSell.userId,
            bestSell.price,
            tradeQty,
            timestamp);

        trades.push_back(trade);

        std::cout
            << "WRITING TRADE TO JSON"
            << std::endl;
            
        std::ifstream inputFile(
            "../api-gateway/data/trades.json");

        json tradeHistory;

        inputFile >> tradeHistory;

        inputFile.close();

        tradeHistory.push_back({{"tradeId", trade.tradeId},
                                {"buyerId", trade.buyerId},
                                {"sellerId", trade.sellerId},
                                {"price", trade.price},
                                {"quantity", trade.quantity},
                                {"timestamp", trade.timestamp}});

        std::ofstream outputFile(
            "../api-gateway/data/trades.json");

        outputFile
            << tradeHistory.dump(4);

        outputFile.close();

        bestBuy.quantity -= tradeQty;
        bestSell.quantity -= tradeQty;

        if (bestBuy.quantity == 0)
        {
            bestBuy.status = FILLED;
        }
        else
        {
            bestBuy.status = PARTIALLY_FILLED;
        }

        if (bestSell.quantity == 0)
        {
            bestSell.status = FILLED;
        }
        else
        {
            bestSell.status = PARTIALLY_FILLED;
        }

        auto buyIt = allOrders.find(bestBuy.orderId);

        if (buyIt != allOrders.end())
        {
            buyIt->second = bestBuy;
        }

        auto sellIt = allOrders.find(bestSell.orderId);

        if (sellIt != allOrders.end())
        {
            sellIt->second = bestSell;
        }

        buyOrders.pop();
        sellOrders.pop();

        if (bestBuy.quantity > 0)
        {
            buyOrders.push(bestBuy);
        }

        if (bestSell.quantity > 0)
        {
            sellOrders.push(bestSell);
        }
        std::cout
            << "Total Trades: "
            << trades.size()
            << std::endl;

        std::cout
            << "TRADE EXECUTED"
            << std::endl;

        std::cout
            << "Buyer: "
            << trade.buyerId
            << std::endl;

        std::cout
            << "Seller: "
            << trade.sellerId
            << std::endl;

        std::cout
            << "Price: "
            << trade.price
            << std::endl;

        std::cout
            << "Quantity: "
            << trade.quantity
            << std::endl;
    }
}

void OrderBook::printBuyOrders() const
{
    auto temp = buyOrders;

    std::cout
        << "\nBUY ORDERS\n";

    while (!temp.empty())
    {
        Order order =
            temp.top();

        std::cout
            << order.orderId
            << " "
            << order.price
            << " "
            << order.quantity
            << std::endl;

        temp.pop();
    }
}

void OrderBook::printSellOrders() const
{
    auto temp = sellOrders;

    std::cout
        << "\nSELL ORDERS\n";

    while (!temp.empty())
    {
        Order order =
            temp.top();

        std::cout
            << order.orderId
            << " "
            << order.price
            << " "
            << order.quantity
            << std::endl;

        temp.pop();
    }
}

void OrderBook::printTrades() const
{
    std::cout
        << "\n===== TRADE HISTORY =====\n";

    for (const Trade &trade : trades)
    {
        std::cout
            << "Trade ID: "
            << trade.tradeId
            << std::endl;

        std::cout
            << "Buyer: "
            << trade.buyerId
            << std::endl;

        std::cout
            << "Seller: "
            << trade.sellerId
            << std::endl;

        std::cout
            << "Price: "
            << trade.price
            << std::endl;

        std::cout
            << "Quantity: "
            << trade.quantity
            << std::endl;

        std::cout
            << "Time: "
            << trade.timestamp
            << std::endl;

        std::cout
            << "------------------"
            << std::endl;
    }
}

void OrderBook::printMarketSnapshot() const
{
    std::cout
        << "\n===== MARKET SNAPSHOT =====\n";
    if (!buyOrders.empty())
    {
        std::cout
            << "Best Buy: "
            << buyOrders.top().price
            << std::endl;
    }
    else
    {
        std::cout
            << "Best Buy: NONE"
            << std::endl;
    }

    if (!sellOrders.empty())
    {
        std::cout
            << "Best Sell: "
            << sellOrders.top().price
            << std::endl;
    }
    else
    {
        std::cout
            << "Best Sell: NONE"
            << std::endl;
    }

    std::cout
        << "Buy Orders: "
        << buyOrders.size()
        << std::endl;

    std::cout
        << "Sell Orders: "
        << sellOrders.size()
        << std::endl;
}

void OrderBook::cancelOrder(const std::string &orderId)

{
    cancelledOrders.insert(orderId);

    if (allOrders.count(orderId))
    {
        auto it = allOrders.find(orderId);

        if (it != allOrders.end())
        {
            it->second.status = CANCELLED;
        }
    }

    std::cout
        << "Cancelled Order: "
        << orderId
        << std::endl;
}

void OrderBook::printOrderHistory() const
{
    std::cout
        << "\n===== ORDER HISTORY =====\n";

    for (const Order &order : orderHistory)
    {
        std::cout
            << "Order ID: "
            << order.orderId
            << std::endl;

        std::cout
            << "User: "
            << order.userId
            << std::endl;

        std::cout
            << "Price: "
            << order.price
            << std::endl;

        std::cout
            << "Quantity: "
            << order.quantity
            << std::endl;

        std::cout
            << "------------------"
            << std::endl;
    }
}

void OrderBook::printAllOrders() const
{
    std::cout
        << "\n===== ALL ORDERS =====\n";

    for (const auto &pair : allOrders)
    {
        const Order &order = pair.second;

        std::cout
            << order.orderId
            << " "
            << order.userId
            << " "
            << order.quantity
            << std::endl;
    }
}

void OrderBook::modifyOrder(
    const std::string &orderId,
    double newPrice,
    int newQuantity)
{
    auto it = allOrders.find(orderId);

    if (it == allOrders.end())
    {
        std::cout
            << "Order not found"
            << std::endl;

        return;
    }

    Order oldOrder = it->second;

    cancelOrder(orderId);

    Order modifiedOrder(
        orderId,
        oldOrder.userId,
        oldOrder.isBuy,
        newPrice,
        newQuantity);

    if (modifiedOrder.isBuy)
    {
        addBuyOrder(modifiedOrder);
    }
    else
    {
        addSellOrder(modifiedOrder);
    }

    std::cout
        << "Order Modified: "
        << orderId
        << std::endl;
}

void OrderBook::printMarketDepth() const
{
    std::map<double, int, std::greater<double>> buyDepth;
    std::map<double, int> sellDepth;

    auto buyTemp = buyOrders;

    while (!buyTemp.empty())
    {
        Order order = buyTemp.top();

        buyDepth[order.price] += order.quantity;

        buyTemp.pop();
    }

    auto sellTemp = sellOrders;

    while (!sellTemp.empty())
    {
        Order order = sellTemp.top();

        sellDepth[order.price] += order.quantity;

        sellTemp.pop();
    }

    std::cout
        << "\n===== MARKET DEPTH =====\n";

    std::cout
        << "\nBUY SIDE\n";

    for (const auto &level : buyDepth)
    {
        std::cout
            << level.first
            << " -> "
            << level.second
            << std::endl;
    }

    std::cout
        << "\nSELL SIDE\n";

    for (const auto &level : sellDepth)
    {
        std::cout
            << level.first
            << " -> "
            << level.second
            << std::endl;
    }
}

bool OrderBook::validateOrder(
    const Order &order) const
{
    if (order.price <= 0)
    {
        std::cout
            << "Invalid Price"
            << std::endl;

        return false;
    }

    if (order.quantity <= 0)
    {
        std::cout
            << "Invalid Quantity"
            << std::endl;

        return false;
    }

    if (allOrders.count(order.orderId))
    {
        std::cout
            << "Duplicate Order ID"
            << std::endl;

        return false;
    }

    return true;
}
