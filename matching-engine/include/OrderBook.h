#ifndef ORDERBOOK_H
#define ORDERBOOK_H

#include "Order.h"
#include "Trade.h"
#include "BuyComparator.h"
#include "SellComparator.h"

#include <queue>
#include <vector>
#include <unordered_map>

class OrderBook
{
private:

    std::priority_queue<
        Order,
        std::vector<Order>,
        BuyComparator
    > buyBook;

    std::priority_queue<
        Order,
        std::vector<Order>,
        SellComparator
    > sellBook;

    std::vector<Trade> trades;

    std::unordered_map<
        std::string,
        bool
    > cancelledOrders;

public:

    void addOrder(const Order& order);

    void cancelOrder(
        const std::string& orderId
    );

    void matchOrders();

    void printTrades();
};

#endif