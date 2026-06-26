import axios from "axios";

const API = "http://localhost:3000/orders";

export async function createOrder(order) {
    const response = await axios.post(API, order);
    return response.data;
}

export async function getOrders() {
    const response = await axios.get(API);
    return response.data;
}