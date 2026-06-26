const pool = require("../database/db");

const fs = require("fs");

exports.getTrades = () => {

    const data =
        fs.readFileSync(
            "./data/trades.json",
            "utf8"
        );

    return JSON.parse(data);

};