import { useState } from "react";
import { createOrder } from "../services/orderService";

function OrderForm() {
  const [orderId, setOrderId] = useState("");
  const [userId, setUserId] = useState("");
  const [price, setPrice] = useState("");
  const [quantity, setQuantity] = useState("");

  const handleSubmit = async (e) => {
    e.preventDefault();

    try {
      const result = await createOrder({
        orderId,
        userId,
        price: Number(price),
        quantity: Number(quantity),
      });

      alert(result.message);

      setOrderId("");
      setUserId("");
      setPrice("");
      setQuantity("");
    } catch (error) {
      console.error(error);

      alert("Order Creation Failed");
    }
  };

  return (
    <form onSubmit={handleSubmit}>
      <h2>Create Order</h2>

      <input
        type="text"
        placeholder="Order ID"
        value={orderId}
        onChange={(e) =>
          setOrderId(e.target.value)
        }
      />

      <br />
      <br />

      <input
        type="text"
        placeholder="User ID"
        value={userId}
        onChange={(e) =>
          setUserId(e.target.value)
        }
      />

      <br />
      <br />

      <input
        type="number"
        placeholder="Price"
        value={price}
        onChange={(e) =>
          setPrice(e.target.value)
        }
      />

      <br />
      <br />

      <input
        type="number"
        placeholder="Quantity"
        value={quantity}
        onChange={(e) =>
          setQuantity(e.target.value)
        }
      />

      <br />
      <br />

      <button type="submit">
        Submit Order
      </button>
    </form>
  );
}

export default OrderForm;