import axios from "axios";

const API = "http://localhost:3000/trades";

export async function getTrades() {

    const response = await axios.get(API);

    return response.data;
}