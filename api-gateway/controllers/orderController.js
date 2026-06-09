const {
    sendOrderToEngine
} = require(
    "../services/engineService"
);

const createOrder = (
    req,
    res
) =>
{
    const order = req.body;

    sendOrderToEngine(order);

    res.status(201).json({
        message:
        "Order received",
        order
    });
};

module.exports = {
    createOrder
};