#include "../include/OrderBook.h"

int main()
{
    OrderBook orderBook;

    orderBook.addBuyOrder(
        Order(
            "B1",
            "USER1",
            true,
            -100,
            50));

    orderBook.addBuyOrder(
        Order(
            "B2",
            "USER2",
            true,
            100,
            -10));

    orderBook.addBuyOrder(
        Order(
            "B3",
            "USER3",
            true,
            100,
            50));

    orderBook.addBuyOrder(
        Order(
            "B3",
            "USER4",
            true,
            120,
            20));

    orderBook.matchOrders();
    orderBook.printMarketSnapshot();
    orderBook.printBuyOrders();
    orderBook.printSellOrders();
    orderBook.printTrades();
    orderBook.printMarketDepth();
    return 0;
}