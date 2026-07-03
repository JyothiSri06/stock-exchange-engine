const pool = require("../database/db");
const client = require("../cache/redisClient");

async function warmCache()
{
    console.log(
        "WARMING CACHE..."
    );

    const result =
        await pool.query(
            "SELECT * FROM orders"
        );

    // await client.set(
    //     "orders",
    //     JSON.stringify(
    //         result.rows
    //     ),
    //     {
    //         EX: 60
    //     }
    // );

    console.log(
        "CACHE READY"
    );
}

module.exports = {
    warmCache
};