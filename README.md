
### Project Title

# Stock Exchange Matching Engine

A production-inspired stock exchange backend system built using **C++, Node.js, PostgreSQL, and Redis**, implementing core trading concepts such as order matching, price-time priority, trade execution, persistent storage, and caching.

---

## Features

### Matching Engine (C++)

* Price-Time Priority Matching
* Buy Order Book
* Sell Order Book
* Partial Order Fills
* Trade Execution Engine
* Trade History Generation
* Market Depth Calculation
* JSON-Based Order Loading

### API Gateway (Node.js + Express)

* Create Order API
* Get Orders API
* Update Order API
* Delete Order API
* Snapshot APIs
* Trade APIs
* Layered Architecture (Routes → Controllers → Services)

### PostgreSQL Integration

* Persistent Order Storage
* Persistent Trade Storage
* CRUD Operations
* Parameterized SQL Queries
* Database-backed Services

### Redis Integration

* Read-Through Caching
* Write-Through Caching
* Cache Invalidation
* Reduced Database Reads
* Faster Order Retrieval

---

## System Architecture

```text
Client
   │
   ▼
Node.js API Gateway
   │
   ├── Redis Cache
   │
   ├── PostgreSQL
   │
   └── C++ Matching Engine
```

---

## Tech Stack

### Backend

* Node.js
* Express.js

### Matching Engine

* C++17
* STL
* Priority Queues

### Database

* PostgreSQL

### Cache

* Redis

### Data Format

* JSON
* nlohmann/json

---

## Implemented Modules

### Order Management

* Create Orders
* Update Orders
* Delete Orders
* Retrieve Orders

### Matching Engine

* Order Book
* Trade Matching
* Partial Fills
* Trade History

### Storage

* PostgreSQL Orders Table
* PostgreSQL Trades Table

### Performance

* Redis Read Cache
* Redis Write-Through Cache

---

## API Endpoints

### Orders

```http
GET /orders
POST /orders
PUT /orders/:orderId
DELETE /orders/:orderId
```

### Trades

```http
GET /trades
```

### Snapshot

```http
GET /snapshot
```

---

## Database Schema

### Orders

```sql
order_id
user_id
is_buy
price
quantity
status
```

### Trades

```sql
trade_id
buyer_id
seller_id
price
quantity
timestamp
```

---
 
# Strong Resume Points

### Version 1 (Recommended)

* Built a low-latency stock exchange matching engine in C++ implementing price-time priority, partial fills, trade execution, trade history, and market depth calculations.
* Developed a Node.js/Express API Gateway exposing RESTful order management APIs and integrating with a custom C++ trading engine.
* Designed PostgreSQL-backed order and trade persistence layer, replacing in-memory storage with database-driven CRUD workflows.
* Implemented Redis read-through and write-through caching strategies, reducing repetitive database reads and improving API response performance.
* Architected a layered backend system (Routes → Controllers → Services → Database/Cache) following production-grade backend engineering practices.

---

### Version 2 (Nokia / Visa / Product Companies)

* Engineered a distributed trading backend using C++, Node.js, PostgreSQL, and Redis, supporting order lifecycle management and trade execution workflows.
* Implemented order book management and matching algorithms based on price-time priority with support for partial order fills.
* Optimized order retrieval through Redis caching and cache consistency mechanisms, minimizing PostgreSQL load.
* Designed normalized database schemas for orders and trades with parameterized SQL queries and asynchronous service-layer abstractions.
* Built scalable REST APIs with clear separation of concerns across routing, controller, service, cache, and persistence layers.

---

### Project Description (Resume)

**Stock Exchange Matching Engine | C++, Node.js, PostgreSQL, Redis**

Built a production-inspired trading system featuring a C++ matching engine, Node.js API Gateway, PostgreSQL persistence, and Redis caching. Implemented price-time priority matching, partial fills, trade history, CRUD APIs, read-through/write-through caching, and layered backend architecture to simulate core exchange infrastructure.

These points are strong enough to use immediately for internship applications while you continue building Days 71+.
