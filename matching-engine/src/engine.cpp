#include <iostream>
#include <string>

#include "../include/json.hpp"

using json = nlohmann::json;

int main()
{
    std::string input;

    std::getline(
        std::cin,
        input
    );

    json order =
        json::parse(input);

    std::string orderId =
        order["orderId"];

    std::string userId =
        order["userId"];

    double price =
        order["price"];

    int quantity =
        order["quantity"];

    std::cout
        << "Order ID: "
        << orderId
        << std::endl;

    std::cout
        << "User ID: "
        << userId
        << std::endl;

    std::cout
        << "Price: "
        << price
        << std::endl;

    std::cout
        << "Quantity: "
        << quantity
        << std::endl;

    return 0;
}