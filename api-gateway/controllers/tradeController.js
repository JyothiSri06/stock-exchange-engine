const tradeService =
require("../services/tradeService");

exports.getTrades = (req, res) => {

    try {

        const trades =
            tradeService.getTrades();

        res.json(trades);

    }

    catch (error) {

        console.error(error);

        res.status(500).json({
            message: "Failed to fetch trades"
        });

    }

};