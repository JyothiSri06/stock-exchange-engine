const path = require("path");
const { spawn } =
require("child_process");

const sendOrderToEngine =
(order) =>
{
    return new Promise(
        (resolve, reject) =>
        {
            const enginePath =
    path.join(
        __dirname,
        "..",
        "..",
        "matching-engine",
        "exchange.exe"
    );

console.log(enginePath);

const engine =
    spawn(enginePath);

            let output = "";

            engine.stdin.write(
                JSON.stringify(order)
            );

            engine.stdin.end();

            engine.stdout.on(
                "data",
                (data) =>
                {
                    output +=
                    data.toString();
                }
            );

            engine.on(
                "close",
                () =>
                {
                    resolve(output);
                }
            );

            engine.on(
                "error",
                (error) =>
                {
                    reject(error);
                }
            );
        }
    );
};

module.exports = {
    sendOrderToEngine
};