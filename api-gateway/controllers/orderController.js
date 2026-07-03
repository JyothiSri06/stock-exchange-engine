const engineService = require("../services/engineService");

const orderService = require("../services/orderService");
console.log(orderService);

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
  try {
    const { orderId, userId, isBuy, price, quantity } = req.body;

    console.log("REQ BODY:", req.body);

    if (!orderId || !userId || isBuy === undefined || !price || !quantity) {
      return res.status(400).json({
        error: "Missing required fields",
      });
    }

    console.log("Step 1");

    const existingOrder =
      await orderService.findOrderById(orderId);

    console.log("Step 2");

    if (existingOrder) {
      return res.status(400).json({
        error: "Order ID already exists",
      });
    }

    console.log("Step 3");

    await orderService.addOrder({
      orderId,
      userId,
      isBuy,
      price,
      quantity,
      status: "OPEN",
    });

    console.log("Step 4");

    engineService.sendOrderToEngine({
      orderId,
      userId,
      isBuy,
      price,
      quantity,
    });

    console.log("Step 5");

    getIO().emit("new-order");

    console.log("Step 6");

    res.json({
      message: "Order stored",
    });

  } catch (err) {

    console.error("===== ERROR =====");
    console.error(err);

    res.status(500).json({
      error: err.message,
    });
  }
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
