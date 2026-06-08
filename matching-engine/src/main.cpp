#include "../include/OrderBook.h"

int main()
{
    OrderBook orderBook;

    orderBook.addOrder(
        Order(
            "B1",
            "BUYER",
            true,
            100,
            100,
            1000
        )
    );

    orderBook.addOrder(
        Order(
            "S1",
            "SELLER1",
            false,
            95,
            20,
            1001
        )
    );

    orderBook.addOrder(
        Order(
            "S2",
            "SELLER2",
            false,
            96,
            30,
            1002
        )
    );

    orderBook.addOrder(
        Order(
            "S3",
            "SELLER3",
            false,
            97,
            50,
            1003
        )
    );

    orderBook.matchOrders();

    orderBook.printTrades();

    return 0;
}