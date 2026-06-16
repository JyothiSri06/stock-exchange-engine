#include "../include/OrderBook.h"

int main()
{
    OrderBook orderBook;

    orderBook.addBuyOrder(
        Order(
            "B1",
            "BUYER1",
            true,
            100,
            100));
    
    orderBook.addBuyOrder(
        Order(
            "B2",
            "BUYER2",
            true,
            100,
            100));

    orderBook.addSellOrder(
        Order(
            "S1",
            "SELLER1",
            false,
            105,
            50));
    
    orderBook.addSellOrder(
        Order(
            "S2",
            "SELLER2",
            false,
            90,
            80));

    orderBook.matchOrders();
    orderBook.printMarketSnapshot();
    orderBook.printBuyOrders();
    orderBook.printSellOrders();
    orderBook.printTrades();
    return 0;
}