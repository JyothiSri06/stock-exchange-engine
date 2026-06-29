#include <iostream>
#include <string>
#include "../include/OrderBook.h"
#include "../include/json.hpp"
#include "../include/Order.h"
#include <fstream>
#include <thread>
#include <chrono>

using json = nlohmann::json;

OrderBook orderBook;
int processedOrders = 0;

void loadOrders()
{
    std::ifstream file(
        "../api-gateway/data/orders.json");

    if (!file.is_open())
    {
        std::cout
            << "Cannot open orders file"
            << std::endl;

        return;
    }

    json orders;

    file >> orders;

    std::cout
        << "Orders Loaded: "
        << orders.size()
        << std::endl;

    if (processedOrders == orders.size())
    {
        return;
    }

    int newOrders = orders.size() - processedOrders;

    if (newOrders > 0)
    {

        for (int i = processedOrders; i < orders.size(); i++)
        {
            auto &item = orders[i];
            std::string orderId =
                item["orderId"];

            std::string userId =
                item["userId"];

            bool isBuy =
                item["isBuy"];

            double price =
                item["price"];

            int quantity =
                item["quantity"];

            Order order(
                orderId,
                userId,
                isBuy,
                price,
                quantity);

            if (isBuy)
            {
                orderBook.addBuyOrder(order);
            }
            else
            {
                orderBook.addSellOrder(order);
            }
        }

        processedOrders = orders.size();

        orderBook.printBuyOrders();

        orderBook.printSellOrders();

        orderBook.matchOrders();

        orderBook.printTrades();
        std::cout
            << "\n===== ENGINE SUMMARY =====\n";

        std::cout
            << "Trades: "
            << orderBook.trades.size()
            << std::endl;

        std::cout
            << "Buy Orders Remaining: "
            << orderBook.buyOrders.size()
            << std::endl;

        std::cout
            << "Sell Orders Remaining: "
            << orderBook.sellOrders.size()
            << std::endl;
    }
}

    int main()
    {

        while (true)
        {
            loadOrders();

            std::this_thread::sleep_for(
                std::chrono::seconds(2));
        }

        return 0;
    }
