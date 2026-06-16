#pragma once

#include <string>

class Trade
{
public:
    static int tradeCounter;

    std::string tradeId;

    std::string buyerId;

    std::string sellerId;

    std::string timestamp;

    double price;

    int quantity;

    Trade(
        const std::string &buyerId,
        const std::string &sellerId,
        double price,
        int quantity,
        const std::string &timestamp);
};