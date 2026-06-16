
#pragma once

#include <queue>

#include "Order.h"
#include "BuyComparator.h"
#include "SellComparator.h"
#include <vector>
#include "Trade.h"
#include <unordered_set>
#include <unordered_map>
#include <map>
class OrderBook
{
public:
    std::priority_queue<
        Order,
        std::vector<Order>,
        BuyComparator>
        buyOrders;

    std::priority_queue<
        Order,
        std::vector<Order>,
        SellComparator>
        sellOrders;

    std::unordered_map<
        std::string,
        Order>
        allOrders;
    std::vector<Trade> trades;
    std::unordered_set<std::string> cancelledOrders;
    std::vector<Order> orderHistory;
    bool validateOrder(
        const Order &order) const;
    void addBuyOrder(
        const Order &order);

    void addSellOrder(
        const Order &order);

    void cancelOrder(
        const std::string &orderId);

    Order getBestBuy() const;

    Order getBestSell() const;

    void matchOrders();

    void printBuyOrders() const;

    void printSellOrders() const;

    void printTrades() const;

    void printMarketSnapshot() const;

    void printOrderHistory() const;

    void printAllOrders() const;

    void modifyOrder(
        const std::string &orderId,
        double newPrice,
        int newQuantity);

    void printMarketDepth() const;
};