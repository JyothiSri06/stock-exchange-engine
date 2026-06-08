#include "../include/OrderBook.h"

void OrderBook::addOrder(
    const Order& order
)
{
    if(order.isBuy)
    {
        buyBook.push(order);
    }
    else
    {
        sellBook.push(order);
    }
}


void OrderBook::cancelOrder(
    const std::string& orderId
)
{
    cancelledOrders[orderId] = true;
}

void OrderBook::printTrades()
{
    for(auto &trade : trades)
    {
        trade.printTrade();
    }
}

void OrderBook::matchOrders()
{
    while(
        !buyBook.empty()
        &&
        !sellBook.empty()
    )
    {
        while(
            !buyBook.empty()
            &&
            cancelledOrders[
                buyBook.top().orderId
            ]
        )
        {
            buyBook.pop();
        }

        while(
            !sellBook.empty()
            &&
            cancelledOrders[
                sellBook.top().orderId
            ]
        )
        {
            sellBook.pop();
        }

        if(
            buyBook.empty()
            ||
            sellBook.empty()
        )
        {
            break;
        }

        Order bestBuy =
            buyBook.top();

        buyBook.pop();

        Order bestSell =
            sellBook.top();

        sellBook.pop();

        if(
            bestBuy.price <
            bestSell.price
        )
        {
            break;
        }

        int tradeQuantity =
            std::min(
                bestBuy.quantity,
                bestSell.quantity
            );

        Trade trade(
            bestBuy.orderId,
            bestSell.orderId,
            bestSell.price,
            tradeQuantity
        );

        trades.push_back(trade);

        bestBuy.quantity -= tradeQuantity;

        bestSell.quantity -= tradeQuantity;

        if(bestBuy.quantity > 0)
        {
            buyBook.push(bestBuy);
        }

        if(bestSell.quantity > 0)
        {
            sellBook.push(bestSell);
        }
    }
}
