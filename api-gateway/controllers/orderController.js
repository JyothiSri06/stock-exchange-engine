const {
    sendOrderToEngine
} =
require(
    "../services/engineService"
);

const createOrder =
async (
    req,
    res
) =>
{
    try
    {
        const result =
            await
            sendOrderToEngine(
                req.body
            );

        res.status(201)
        .json({
            engineResponse:
                result
        });
    }
    catch(error)
    {
        res.status(500)
        .json({
            error:
                error.message
        });
    }
};

module.exports = {
    createOrder
};