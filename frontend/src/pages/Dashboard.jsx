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

      console.log(
        `[FRONTEND] Loaded ${data.length} orders`
      );
      setOrders(data);

    } catch (error) {

      console.error(error);

    }

  }

  async function loadTrades() {

    try {

      const data = await getTrades();

      console.log(
        `[FRONTEND] Loaded ${data.length} trades`
      );
      setTrades(data);

    }

    catch (error) {

      console.error(error);

    }

  }


  useEffect(() => {

    loadOrders();
    loadTrades();

    const onConnect = () => {
      console.log("Connected:", socket.id);
    };

    const onNewOrder = () => {
      console.log("[FRONTEND] New Order");
      loadOrders();
    };

    const onNewTrade = () => {
      console.log("[FRONTEND] New Trade");
      loadTrades();
    };

    socket.on("connect", onConnect);
    socket.on("new-order", onNewOrder);
    socket.on("new-trade", onNewTrade);

    return () => {
      socket.off("connect", onConnect);
      socket.off("new-order", onNewOrder);
      socket.off("new-trade", onNewTrade);
    };

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