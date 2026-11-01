import { useLocation } from "react-router-dom";

function OrderConfirmed() {
  const location = useLocation();

  const { orderId, items, total } = location.state;

  return (
    <div className="order-confirmed">
      <h1>✓ Order Confirmed!</h1>
      <p>Your order has been placed successfully.</p>

      <h3>Order ID: {orderId}</h3>

      <h2>Order Summary</h2>

      {items.map((item) => (
        <div key={item.id} className="order-item">
          <img src={item.thumbnail} alt={item.title} width="60" />

          <div>
            <p>{item.title}</p>
            <p>Quantity: {item.quantity}</p>
          </div>

          <p>${(item.price * item.quantity).toFixed(2)}</p>
        </div>
      ))}

      <h3>Total: ${total.toFixed(2)}</h3>
    </div>
  );
}

export default OrderConfirmed;
