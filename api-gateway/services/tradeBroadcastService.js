const fs = require("fs");

const { getIO } =
  require("../socket");

let lastTradeCount = 0;

exports.monitorTrades = () => {

  setInterval(() => {

    const data =
      fs.readFileSync(
        "./data/trades.json",
        "utf8"
      );

    const trades =
      JSON.parse(data);

    if (
      trades.length >
      lastTradeCount
    )
    {
      const newestTrade =
        trades[
          trades.length - 1
        ];

      getIO().emit(
        "new-trade",
        newestTrade
      );

      console.log(
        "TRADE BROADCASTED"
      );

      lastTradeCount =
        trades.length;
    }

  }, 2000);

};