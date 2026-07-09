
const fs = require("fs");
const pool = require("../database/db");

const orders = [];

exports.getOrders = async () => {

    console.log("===== GET ORDERS =====");

    const data = fs.readFileSync(
        "./data/orders.json",
        "utf8"
    );

    console.log(data);

    return JSON.parse(data);
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
      order.isBuy,
      order.price,
      order.quantity,
      order.status,
    ],
  );
  const result = await pool.query("SELECT * FROM orders");

  // await client.set(`order:${order.orderId}`, JSON.stringify(order), {
  //   EX: 60,
  // });
};

exports.findOrderById = async (orderId) => {
  // const cachedOrder = await client.get(`order:${orderId}`);

  // if (cachedOrder) {
  //   console.log("ORDER FROM REDIS");

  //   return JSON.parse(cachedOrder);
  // }

  // console.log("ORDER FROM POSTGRES");

  const result = await pool.query(
    `
      SELECT *
      FROM orders
      WHERE order_id = $1
      `,
    [orderId],
  );

  // if (result.rows[0]) {
  //   await client.set(`order:${orderId}`, JSON.stringify(result.rows[0]), {
  //     EX: 60,
  //   });
  // }

  return result.rows[0];
};

exports.deleteOrder = async (orderId) => {
  const data = fs.readFileSync("./data/orders.json", "utf8");

  const orders = JSON.parse(data);

  const index = orders.findIndex((order) => order.orderId === orderId);

  if (index === -1) {
    return null;
  }

  const deletedOrder = orders.splice(index, 1)[0];

  fs.writeFileSync("./data/orders.json", JSON.stringify(orders, null, 4));

  return deletedOrder;
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

  // await client.del("orders");

  return result.rowCount > 0;
};

exports.getAllOrders = async () => {
  const result = await pool.query(`
        SELECT *
        FROM orders
        ORDER BY order_id DESC
    `);

  return result.rows;
};
