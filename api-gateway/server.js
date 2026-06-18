require("dotenv").config();

const express = require("express");

const app = express();

app.use(express.json());

const healthRoutes =
    require("./routes/healthRoutes");

const snapshotRoutes =
    require("./routes/snapshotRoutes");

const tradeRoutes =
    require("./routes/tradeRoutes");

const orderRoutes =
    require("./routes/orderRoutes");


app.use(
    "/health",
    healthRoutes
);

app.use(
    "/snapshot",
    snapshotRoutes
);

app.use(
    "/trades",
    tradeRoutes
);

app.use(
    "/orders",
    orderRoutes
);

const PORT = 3000;

app.listen(PORT, () => {
    console.log(
        `Server running on port ${PORT}`
    );
}); 