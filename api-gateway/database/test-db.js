const pool = require("./db.js");

pool.query(
    "SELECT NOW()",
    (err, result) => {

        if (err) {
            console.log(err);
        } else {
            console.log(result.rows);
        }

        pool.end();
    }
);