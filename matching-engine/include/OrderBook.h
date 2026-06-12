#pragma once

#include <vector>

#include "Order.h"

class OrderBook
{
public:

    std::vector<Order> orders;

    void addOrder(
        const Order& order
    );
};