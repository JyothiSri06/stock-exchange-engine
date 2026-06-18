const tradeService =
    require("../services/tradeService");

exports.getTrades = (req, res) => {

    const trades =
        tradeService.getTrades();

    res.json(trades);
};