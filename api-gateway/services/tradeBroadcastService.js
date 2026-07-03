const fs = require("fs");
const { getIO } = require("../socket");

let lastTradeCount = 0;

try {
    const data = fs.readFileSync("./data/trades.json", "utf8");
    const trades = JSON.parse(data);
    lastTradeCount = trades.length;
} catch (err) {
    lastTradeCount = 0;
}

exports.monitorTrades = () => {

    setInterval(() => {

        const data = fs.readFileSync("./data/trades.json","utf8");

        const trades = JSON.parse(data);

        if (trades.length > lastTradeCount) {

            for (let i = lastTradeCount; i < trades.length; i++) {

                getIO().emit("new-trade", trades[i]);

                console.log(`[SOCKET] Broadcasted ${trades[i].tradeId}`);
            }

            lastTradeCount = trades.length;
        }

    },2000);

};