/*
 * Tool Used: ChatGPT
 * Purpose: Generate checkout page
 * Prompts Used: "write me static checkout page"
 * Personal Verification & Edits: The code follows standard react practices.
 */

import { useNavigate } from "react-router-dom";

export default function Checkout() {
  const navigate = useNavigate();
  const cart = JSON.parse(localStorage.getItem("cart") || "[]");

  const subtotal = cart.reduce(
    (total, item) => total + item.price * item.quantity,
    0,
  );

  const handlePlaceOrder = () => {
    navigate("/order-confirmed", {
      state: {
        orderId: `ORD-${Date.now()}`,
        items: cart,
        total: subtotal,
      },
    });

    localStorage.removeItem("cart");
  };

  return (
    <div className="checkout-page flex flex-col gap-2">
      <h1 className="h1-class">Checkout</h1>

      <div className="checkout-layout">
        {/* Checkout Form */}
        <div className="checkout-form flex flex-col gap-2">
          {/* Contact */}
          <section className="checkout-section flex flex-col gap-2">
            <h3 className="h3-class">Contact Information</h3>

            <div className="form-group">
              <label>Email Address</label>
              <input type="email" placeholder="you@example.com" />
            </div>

            <div className="form-group">
              <label>Phone Number</label>
              <input type="tel" placeholder="+91 98765 43210" />
            </div>
          </section>

          {/* Shipping */}
          <section className="checkout-section flex flex-col gap-2">
            <h3 className="h3-class">Shipping Address</h3>

            <div className="form-row">
              <div className="form-group">
                <label>First Name</label>
                <input type="text" placeholder="John" />
              </div>

              <div className="form-group">
                <label>Last Name</label>
                <input type="text" placeholder="Doe" />
              </div>
            </div>

            <div className="form-group">
              <label>Address</label>
              <input type="text" placeholder="Street address" />
            </div>

            <div className="form-group">
              <label>Apartment, Suite, etc. (Optional)</label>
              <input type="text" placeholder="Apartment 101" />
            </div>

            <div className="form-row">
              <div className="form-group">
                <label>City</label>
                <input type="text" placeholder="Mumbai" />
              </div>

              <div className="form-group">
                <label>Postal Code</label>
                <input type="text" placeholder="400001" />
              </div>
            </div>

            <div className="form-group">
              <label>State</label>
              <input type="text" placeholder="Maharashtra" />
            </div>
          </section>

          {/* Payment */}
          <section className="checkout-section flex flex-col gap-2">
            <h3 className="h3-class">Payment Method</h3>

            <label className="payment-option">
              <input type="radio" name="payment" defaultChecked />
              <span>Credit / Debit Card</span>
            </label>

            <label className="payment-option">
              <input type="radio" name="payment" />
              <span>UPI</span>
            </label>

            <label className="payment-option">
              <input type="radio" name="payment" />
              <span>Cash on Delivery</span>
            </label>

            <div className="form-group">
              <label>Card Number</label>
              <input type="text" placeholder="1234 5678 9012 3456" />
            </div>

            <div className="form-row">
              <div className="form-group">
                <label>Expiry Date</label>
                <input type="text" placeholder="MM/YY" />
              </div>

              <div className="form-group">
                <label>CVV</label>
                <input type="password" placeholder="123" />
              </div>
            </div>
          </section>
        </div>

        {/* Order Summary */}
        <aside className="checkout-summary flex flex-col gap-2">
          <h3 className="h3-class">Order Summary</h3>

          <div className="checkout-products flex flex-col gap-1">
            {cart.map((item) => (
              <div
                className="checkout-product flex flex-row gap-1"
                key={item.id}
              >
                <img src={item.thumbnail} alt={item.title} />

                <div className="flex flex-col gap-1 checkout-product-info">
                  <span className="font-bold">{item.title}</span>
                  <span className="text-muted text-xs">
                    Quantity: {item.quantity}
                  </span>
                </div>

                <span className="font-bold">
                  ${(item.price * item.quantity).toFixed(2)}
                </span>
              </div>
            ))}
          </div>

          <div className="border-b"></div>

          <div className="flex flex-row justify-between">
            <span className="text-muted">Subtotal</span>
            <span>${subtotal.toFixed(2)}</span>
          </div>

          <div className="flex flex-row justify-between">
            <span className="text-muted">Shipping</span>
            <span>Free</span>
          </div>

          <div className="flex flex-row justify-between">
            <span className="text-muted">Tax</span>
            <span>$0.00</span>
          </div>

          <div className="border-b"></div>

          <div className="flex flex-row justify-between font-bold">
            <span>Total</span>
            <span className="checkout-total">${subtotal.toFixed(2)}</span>
          </div>

          <button onClick={handlePlaceOrder} className="checkout-place-order">
            Place Order
          </button>

          <p className="text-muted text-xs checkout-note">
            By placing your order, you agree to our Terms and Conditions.
          </p>
        </aside>
      </div>
    </div>
  );
}
