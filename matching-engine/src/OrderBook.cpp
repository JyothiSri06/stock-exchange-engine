#include "../include/OrderBook.h"

void OrderBook::addOrder(
    const Order& order
)
{
    orders.push_back(order);
}