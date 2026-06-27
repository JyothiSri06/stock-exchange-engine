const engineService = require("../services/engineService");

const orderService = require("../services/orderService");

const { getIO } = require("../socket");

exports.getOrders = async (req, res) => {
  try {
    const orders = await orderService.getAllOrders();

    res.json(orders);
  } catch (error) {
    console.error(error);

    res.status(500).json({
      message: "Failed to fetch orders",
    });
  }
};

exports.createOrder = async (req, res) => {
  const { orderId, userId, isBuy, price, quantity } = req.body;

  console.log("REQ BODY:", req.body);
  console.log("isBuy =", isBuy);

  if (!orderId || !userId || isBuy === undefined || !price || !quantity) {
    return res.status(400).json({
      error: "Missing required fields",
    });
  }

  const existingOrder = await orderService.findOrderById(orderId);

  if (existingOrder) {
    return res.status(400).json({
      error: "Order ID already exists",
    });
  }
  await orderService.addOrder({
    orderId,
    userId,
    isBuy,
    price,
    quantity,
    status: "OPEN",
  });

  getIO().emit("new-order", {
    orderId,
    userId,
    isBuy,
    price,
    quantity,
    status: "OPEN",
  });

  engineService.sendOrderToEngine({
    orderId,
    userId,
    isBuy,
    price,
    quantity,
  });

  res.json({
    message: "Order stored",
  });
};

exports.deleteOrder = async (req, res) => {
  const orderId = req.params.orderId;

  const deleted = await orderService.deleteOrder(orderId);

  if (!deleted) {
    return res.status(404).json({
      error: "Order not found",
    });
  }

  res.json({
    message: "Order deleted",
  });
};

exports.updateOrder = async (req, res) => {
  const orderId = req.params.orderId;

  const { price, quantity } = req.body;

  if (!price || !quantity) {
    return res.status(400).json({
      error: "Missing required fields",
    });
  }

  const updated = await orderService.updateOrder(orderId, price, quantity);

  if (!updated) {
    return res.status(404).json({
      error: "Order not found",
    });
  }

  res.json({
    message: "Order updated",
  });
};
