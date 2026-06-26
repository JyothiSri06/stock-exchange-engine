function TradesTable({ trades }) {

    return (

        <table border="1">

            <thead>

                <tr>

                    <th>Trade ID</th>
                    <th>Buyer</th>
                    <th>Seller</th>
                    <th>Price</th>
                    <th>Quantity</th>

                </tr>

            </thead>

            <tbody>

                {trades.map((trade,index) => (

                    <tr key={`${trade.tradeId}-${index}`}>
                        <td>{trade.tradeId}</td>
                        <td>{trade.buyerId}</td>
                        <td>{trade.sellerId}</td>
                        <td>{trade.price}</td>
                        <td>{trade.quantity}</td>
                    </tr>

                ))}

            </tbody>

        </table>

    );

}

export default TradesTable;

