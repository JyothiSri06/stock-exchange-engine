#include <iostream>
#include <string>

#include "../include/json.hpp"
#include "../include/Order.h"
using json = nlohmann::json;

int main()
{
    std::string input;

    std::getline(
        std::cin,
        input);

    json order =
        json::parse(input);

    std::string orderId =
        order["orderId"];

    std::string userId =
        order["userId"];

    bool isBuy =
        order["isBuy"];

    double price =
        order["price"];

    int quantity =
        order["quantity"];

    Order newOrder(
        orderId,
        userId,
        isBuy,
        price,
        quantity);

    std::cout
        << "Order ID: "
        << newOrder.orderId
        << std::endl;

    std::cout
        << "User ID: "
        << newOrder.userId
        << std::endl;

    std::cout
        << "Is Buy: "
        << newOrder.isBuy
        << std::endl;

    std::cout
        << "Price: "
        << newOrder.price
        << std::endl;

    std::cout
        << "Quantity: "
        << newOrder.quantity
        << std::endl;

    return 0;
}