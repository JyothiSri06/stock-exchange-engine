const fs =
    require("fs");

exports.sendOrderToEngine =
    (order) => {

        const filePath =
            "./data/orders.json";

        const orders =
            JSON.parse(
                fs.readFileSync(
                    filePath,
                    "utf8"
                )
            );

        console.log("ENGINE ORDER:", order);
        
        orders.push(order);
        
        fs.writeFileSync(
            filePath,
            JSON.stringify(
                orders,
                null,
                2
            )
        );

        console.log(
            "ORDER WRITTEN TO FILE"
        );

        return {
            accepted: true
        };
    };