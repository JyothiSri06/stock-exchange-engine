#include "../include/Trade.h"
int Trade::tradeCounter = 1;
Trade::Trade(
    const std::string &buyerId,
    const std::string &sellerId,
    double price,
    int quantity,
    const std::string &timestamp)
{

    this->tradeId =
        "T" +
        std::to_string(tradeCounter);
    tradeCounter++;

    this->buyerId = buyerId;

    this->sellerId = sellerId;

    this->price = price;

    this->quantity = quantity;

    this->timestamp = timestamp;
}

 