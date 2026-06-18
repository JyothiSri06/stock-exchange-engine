const client =
    require("./redisClient");

async function test()
{
    await client.set(
        "test",
        "hello"
    );

    const value =
        await client.get(
            "test"
        );

    console.log(value);

    process.exit();
}

test();