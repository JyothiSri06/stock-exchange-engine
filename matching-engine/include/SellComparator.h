#pragma once

#include "Order.h"

class SellComparator
{
public:
    bool operator()(
        const Order &a,
        const Order &b) const
    {
        if (a.price == b.price)
        {
            return a.timestamp > b.timestamp;
        }

        return a.price > b.price;
    }
};