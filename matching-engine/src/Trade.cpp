#include "../include/Trade.h"
#include <iostream>

Trade::Trade(
    std::string buyOrderId,
    std::string sellOrderId,
    double price,
    int quantity
)
{
    this->buyOrderId = buyOrderId;
    this->sellOrderId = sellOrderId;
    this->price = price;
    this->quantity = quantity;
}

void Trade::printTrade()
{
    std::cout << "TRADE EXECUTED" << std::endl;

    std::cout << "Buy Order: "
              << buyOrderId
              << std::endl;

    std::cout << "Sell Order: "
              << sellOrderId
              << std::endl;

    std::cout << "Price: "
              << price
              << std::endl;

    std::cout << "Quantity: "
              << quantity
              << std::endl;
}