function OrdersTable({ orders }) {

    console.log("OrdersTable:", orders);
    
    return (

        <table border="1">

            <thead>

                <tr>
                    <th>Order ID</th>
                    <th>User</th>
                    <th>Price</th>
                    <th>Quantity</th>
                </tr>

            </thead>

            <tbody>

                {orders.map((order) => (

                    <tr key={order.order_id}>

                        <td>{order.order_id}</td>
                        <td>{order.user_id}</td>
                        <td>{order.price}</td>
                        <td>{order.quantity}</td>

                    </tr>

                ))}

            </tbody>

        </table>

    );
}

export default OrdersTable;