const engineService = require("../services/engineService");

const orderService = require("../services/orderService");

const { getIO } = require("../socket");

exports.getOrders = async (req, res) => {

    const orders =
        await orderService.getOrders();

    res.json(orders);
};

exports.createOrder = async (req, res) => {
  const { orderId, userId, price, quantity } = req.body;

  if (!orderId || !userId || !price || !quantity) {
    return res.status(400).json({
      error: "Missing required fields",
    });
  }

  const existingOrder = await orderService.findOrderById(orderId);

  getIO().emit(
  "new-order",
  {
    orderId,
    userId,
    price,
    quantity,
    status: "OPEN"
  }
);

  if (existingOrder) {
    return res.status(400).json({
      error: "Order ID already exists",
    });
  }
  await orderService.addOrder({
    orderId,
    userId,
    price,
    quantity,
    status: "OPEN",
  });

  engineService.sendOrderToEngine({
    orderId,
    userId,
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
