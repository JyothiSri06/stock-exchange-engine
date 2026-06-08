# Real-Time Stock Exchange Matching Engine

A high-performance C++ order matching engine implementing:

- Price-Time Priority
- Partial Fills
- Multiple Matches
- Order Cancellation (Lazy Deletion)
- Trade History

## Technologies

- C++
- STL
- Priority Queue
- Unordered Map

## Features

- Buy Order Book
- Sell Order Book
- Matching Engine
- Trade Execution
- Cancellation Support

## Architecture

Order → OrderBook → Matching Engine → Trade History

Client Order
      |
      v
 OrderBook
   /     \
BuyBook SellBook
      |
      v
 Matching Engine
      |
      v
 Trade History