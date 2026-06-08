#ifndef SELL_COMPARATOR_H
#define SELL_COMPARATOR_H

#include "Order.h"

struct SellComparator
{
    bool operator()(const Order& a, const Order& b)
    {
        if(a.price == b.price)
        {
            return a.timestamp > b.timestamp;
        }

        return a.price > b.price;
    }
};

#endif