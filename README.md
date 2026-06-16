# Stock Exchange Matching Engine

## Overview

A stock exchange matching engine built in C++ implementing
price-time priority order matching.

## Features

- Buy Order Book
- Sell Order Book
- Price-Time Priority
- Partial Fills
- Trade History
- Order History
- Order Cancellation
- Order Modification
- Market Snapshot
- Market Depth
- Order Validation

## Data Structures Used

- Priority Queue
- Unordered Map
- Unordered Set
- Vector
- Map

## Architecture

User Orders
    |
    v
OrderBook
    |
    v
Matching Engine
    |
    v
Trade History

## Build

g++ src/main.cpp src/Order.cpp src/OrderBook.cpp src/Trade.cpp -o exchange.exe

## Run

./exchange.exe

## Future Improvements

- REST APIs
- PostgreSQL
- WebSockets
- Docker
- Concurrency