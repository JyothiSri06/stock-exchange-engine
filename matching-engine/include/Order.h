#ifndef ORDER_H
#define ORDER_H

#include <string>

class Order
{
public:
    std::string orderId;
    std::string userId;

    bool isBuy;

    double price;

    int quantity;

    long timestamp;

    Order(
        std::string orderId,
        std::string userId,
        bool isBuy,
        double price,
        int quantity,
        long timestamp
    );

    void printOrder();
};

#endif