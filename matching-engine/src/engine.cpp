#include <iostream>
#include <string>

#include "../include/OrderBook.h"
#include "../include/json.hpp"
#include "../include/Order.h"
using json = nlohmann::json;

int testEngine()
{
    std::string input;

    std::getline(
        std::cin,
        input);

    json order =
        json::parse(input);

    std::string orderId =
        order["orderId"];

    std::string userId =
        order["userId"];

    bool isBuy =
        order["isBuy"];

    double price =
        order["price"];

    int quantity =
        order["quantity"];

    Order newOrder(
        orderId,
        userId,
        isBuy,
        price,
        quantity);

    OrderBook book;

    if (newOrder.isBuy)
    {
        book.addBuyOrder(
            newOrder);
    }
    else
    {
        book.addSellOrder(
            newOrder);
    }  
    book.matchOrders();
    if (book.buyOrders.size() > 0)
    {
        Order bestBuy = book.getBestBuy();

        std::cout
            << "Best Buy: "
            << bestBuy.price
            << std::endl;
    }

    if (book.sellOrders.size() > 0)
    {
        Order bestSell = book.getBestSell();

        std::cout
            << "Best Sell: "
            << bestSell.price
            << std::endl;
    }

    std::cout
        << "Buy Orders: "
        << book.buyOrders.size()
        << std::endl;

    std::cout
        << "Sell Orders: "
        << book.sellOrders.size()
        << std::endl;

    std::cout
        << "Order ID: "
        << newOrder.orderId
        << std::endl;

    std::cout
        << "User ID: "
        << newOrder.userId
        << std::endl;

    std::cout
        << "Is Buy: "
        << newOrder.isBuy
        << std::endl;

    std::cout
        << "Price: "
        << newOrder.price
        << std::endl;

    std::cout
        << "Quantity: "
        << newOrder.quantity
        << std::endl;

    return 0;
}