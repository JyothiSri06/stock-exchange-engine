import OrderForm from "../components/OrderForm";

import { useEffect, useState } from "react";

import OrdersTable from "../components/OrdersTable";

import { getOrders } from "../services/orderService";

import TradesTable from "../components/TradesTable";

import { getTrades } from "../services/tradeService";

import socket from "../services/socketService";

function Dashboard() {

  const [orders, setOrders] = useState([]);

  const [trades, setTrades] = useState([]);

  async function loadOrders() {

    try {

      const data = await getOrders();

      console.log("Orders:", data);

      setOrders(data);

    } catch (error) {

      console.error(error);

    }

  }

  async function loadTrades() {

    try {

      const data = await getTrades();

      console.log(data[0]);

      setTrades(data);

    }

    catch (error) {

      console.error(error);

    }

  }

  useEffect(() => {

    loadOrders();

    loadTrades();

    socket.on("new-order", () => {

      console.log("New Order Received");

      loadOrders();

    });

    return () => {

      socket.off("new-order");
    };

  }, []);

  useEffect(() => {

    socket.on("connect", () => {

      console.log("Connected:", socket.id);

    });

  }, []);

  return (
    <div>

      <h1>Stock Exchange Dashboard</h1>

      <OrderForm />

      <h2>Orders</h2>

      <OrdersTable orders={orders} />

      <h2>Live Trades</h2>

      <TradesTable trades={trades} />

    </div>
  );
}

export default Dashboard;