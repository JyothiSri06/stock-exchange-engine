require("dotenv").config();

const express = require("express");
const http = require("http");

const app = express();
app.use(express.json());

const server = http.createServer(app);

const { Server } = require("socket.io");

const { setIO } = require("./socket");

const { monitorTrades } = require("./services/tradeBroadcastService");

const io = new Server(server, {
  cors: {
    origin: "*",
  },
});

setIO(io);

const healthRoutes = require("./routes/healthRoutes");

const snapshotRoutes = require("./routes/snapshotRoutes");

const tradeRoutes = require("./routes/tradeRoutes");

const orderRoutes = require("./routes/orderRoutes");

const { warmCache } = require("./services/cacheWarmupService");

app.use("/health", healthRoutes);

app.use("/snapshot", snapshotRoutes);

app.use("/trades", tradeRoutes);

app.use("/orders", orderRoutes);

io.on("connection", (socket) => {
  console.log("CLIENT CONNECTED:", socket.id);

  socket.on("disconnect", () => {
    console.log("CLIENT DISCONNECTED:", socket.id);
  });
});

const PORT = 3000;

server.listen(PORT, () => {
  console.log(`Server running on port ${PORT}`);
});

monitorTrades();
