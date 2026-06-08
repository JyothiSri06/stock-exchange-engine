#include "../include/Order.h"
#include <iostream>

Order::Order(
    std::string orderId,
    std::string userId,
    bool isBuy,
    double price,
    int quantity,
    long timestamp
)
{
    this->orderId = orderId;
    this->userId = userId;
    this->isBuy = isBuy;
    this->price = price;
    this->quantity = quantity;
    this->timestamp = timestamp;
}

void Order::printOrder()
{
    std::cout << "------------------" << std::endl;
    std::cout << "Order ID: " << orderId << std::endl;
    std::cout << "User ID: " << userId << std::endl;
    std::cout << "Type: " << (isBuy ? "BUY" : "SELL") << std::endl;
    std::cout << "Price: " << price << std::endl;
    std::cout << "Quantity: " << quantity << std::endl;
    std::cout << "Timestamp: " << timestamp << std::endl;
}