const { io } =
  require("socket.io-client");

const socket =
  io("http://localhost:3000");

socket.on("connect", () => {
  console.log(
    "CONNECTED:",
    socket.id
  );
});

socket.on(
  "new-order",
  (order) => {
    console.log(
      "NEW ORDER:",
      order
    );
  }
);

socket.on(
  "new-trade",
  (trade) => {

    console.log(
      "NEW TRADE:",
      trade
    );

  }
);
