#pragma once

#include <string>
#include <ctime>

enum OrderStatus
{
    OPEN,
    PARTIALLY_FILLED,
    FILLED,
    CANCELLED
};
class Order
{
public:

    std::string orderId;
    std::string userId;

    bool isBuy;

    double price;

    int quantity;

    OrderStatus status;
    
    std::time_t timestamp;

    Order(
        const std::string& orderId,
        const std::string& userId,
        bool isBuy,
        double price,
        int quantity
    );
};