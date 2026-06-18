const express = require("express");

const router = express.Router();

const tradeController =
    require("../controllers/tradeController");

router.get(
    "/",
    tradeController.getTrades
);

module.exports = router;