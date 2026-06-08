#ifndef TRADE_H
#define TRADE_H

#include <string>

class Trade
{
public:
    std::string buyOrderId;

    std::string sellOrderId;

    double price;

    int quantity;

    Trade(
        std::string buyOrderId,
        std::string sellOrderId,
        double price,
        int quantity
    );

    void printTrade();
};

#endif