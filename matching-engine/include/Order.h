#pragma once

#include <string>

class Order
{
public:

    std::string orderId;
    std::string userId;

    bool isBuy;

    double price;

    int quantity;

    Order(
        const std::string& orderId,
        const std::string& userId,
        bool isBuy,
        double price,
        int quantity
    );
};