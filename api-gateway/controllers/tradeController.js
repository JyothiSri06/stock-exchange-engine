const tradeService =
    require("../services/tradeService");

exports.getTrades = async (req, res) => {

    const trades =
        await tradeService.getTrades();

    res.json(trades);
};