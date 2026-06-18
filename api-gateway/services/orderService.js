const pool = require("../database/db");
const client = require("../cache/redisClient");

const orders = [
  {
    orderId: "B1",
    userId: "BUYER1",
    price: 100,
    quantity: 60,
    status: "OPEN",
  },
  {
    orderId: "B2",
    userId: "BUYER2",
    price: 100,
    quantity: 40,
    status: "OPEN",
  },
];

exports.getOrders = async () => {
  const cachedOrders = await client.get("orders");

  if (cachedOrders) {
    console.log("READING FROM REDIS");

    return JSON.parse(cachedOrders);
  }

  console.log("READING FROM POSTGRES");

  const result = await pool.query("SELECT * FROM orders");

  await client.set("orders", JSON.stringify(result.rows));

  return result.rows;
};
exports.addOrder = async (order) => {
  await pool.query(
    `
        INSERT INTO orders
        (
            order_id,
            user_id,
            is_buy,
            price,
            quantity,
            status
        )
        VALUES
        (
            $1,
            $2,
            $3,
            $4,
            $5,
            $6
        )
        `,
    [
      order.orderId,
      order.userId,
      true,
      order.price,
      order.quantity,
      order.status,
    ],
  );
  const result = await pool.query("SELECT * FROM orders");

  await client.set("orders", JSON.stringify(result.rows));
};

exports.findOrderById = async (orderId) => {
  const result = await pool.query(
    `
            SELECT *
            FROM orders
            WHERE order_id = $1
            `,
    [orderId],
  );

  return result.rows[0];
};

exports.deleteOrder = async (orderId) => {
  const result = await pool.query(
    `
            DELETE FROM orders
            WHERE order_id = $1
            `,
    [orderId],
  );

  await client.del("orders");

  return result.rowCount > 0;
};

exports.updateOrder = async (orderId, price, quantity) => {
  const result = await pool.query(
    `
            UPDATE orders
            SET
                price = $1,
                quantity = $2
            WHERE order_id = $3
            `,
    [price, quantity, orderId],
  );

  await client.del("orders");

  return result.rowCount > 0;
};
