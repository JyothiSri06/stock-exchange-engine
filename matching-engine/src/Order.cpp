#include "../include/Order.h"

Order::Order(
    const std::string& orderId,
    const std::string& userId,
    bool isBuy,
    double price,
    int quantity
)
{
    this->orderId = orderId;

    this->userId = userId;

    this->isBuy = isBuy;

    this->price = price;

    this->quantity = quantity;

    this->status = OPEN;

    this->timestamp = std::time(nullptr);
} 