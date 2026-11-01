/*
 * Tool Used: ChatGPT
 * Purpose: Generate cart page
 * Prompts Used: "write me a cart page where the data is stored in localStorage with different products object comma seperated"
 * Personal Verification & Edits: The code follows standard react practices.
 */

import { useEffect, useState } from "react";
import { useNavigate } from "react-router-dom";

export default function Cart() {
  const navigate = useNavigate();
  // Load cart from localStorage when component mounts
  const [cart, setCart] = useState(() => {
    try {
      return JSON.parse(localStorage.getItem("cart")) || [];
    } catch {
      return [];
    }
  });

  // Save cart whenever it changes
  useEffect(() => {
    localStorage.setItem("cart", JSON.stringify(cart));
  }, [cart]);

  // Increase quantity
  function increaseQuantity(id) {
    setCart((prev) =>
      prev.map((item) =>
        item.id === id ? { ...item, quantity: item.quantity + 1 } : item,
      ),
    );
  }

  // Decrease quantity
  function decreaseQuantity(id) {
    setCart((prev) =>
      prev.map((item) =>
        item.id === id
          ? { ...item, quantity: Math.max(1, item.quantity - 1) }
          : item,
      ),
    );
  }

  // Remove product
  function removeProduct(id) {
    setCart((prev) => prev.filter((item) => item.id !== id));
  }

  // Calculate subtotal
  const subtotal = cart.reduce(
    (total, item) => total + item.price * item.quantity,
    0,
  );

  if (cart.length === 0) {
    return (
      <div className="empty-cart flex flex-col items-center justify-center gap-2">
        <h1 className="h1-class">Your Cart is Empty</h1>
        <p className="text-muted">Looks like you haven't added anything yet.</p>
      </div>
    );
  }

  return (
    <div className="cart-page flex flex-col gap-2">
      <h1 className="h1-class">Shopping Cart</h1>

      <div className="cart-layout">
        {/* Cart Items */}
        <div className="cart-items flex flex-col gap-1">
          {cart.map((product) => (
            <div className="cart-item flex flex-row gap-2" key={product.id}>
              <img
                src={product.thumbnail}
                alt={product.title}
                className="cart-image"
              />

              <div className="cart-item-info flex flex-col gap-1">
                <h3 className="h3-class">{product.title}</h3>

                <span className="text-muted text-xs">
                  {product.brand || product.category}
                </span>

                <span className="font-bold">${product.price.toFixed(2)}</span>

                {/* Quantity Controls */}
                <div className="flex flex-row items-center gap-1">
                  <button
                    className="quantity-btn"
                    onClick={() => decreaseQuantity(product.id)}
                  >
                    -
                  </button>

                  <span>{product.quantity}</span>

                  <button
                    className="quantity-btn"
                    onClick={() => increaseQuantity(product.id)}
                  >
                    +
                  </button>
                </div>
              </div>

              <div className="cart-item-end flex flex-col justify-between">
                <span className="font-bold">
                  ${(product.price * product.quantity).toFixed(2)}
                </span>

                <button
                  className="remove-btn"
                  onClick={() => removeProduct(product.id)}
                >
                  Remove
                </button>
              </div>
            </div>
          ))}
        </div>

        {/* Order Summary */}
        <div className="cart-summary flex flex-col gap-2">
          <h3 className="h3-class">Order Summary</h3>

          <div className="flex flex-row justify-between">
            <span className="text-muted">Items</span>
            <span>{cart.reduce((sum, item) => sum + item.quantity, 0)}</span>
          </div>

          <div className="flex flex-row justify-between">
            <span className="text-muted">Subtotal</span>
            <span>${subtotal.toFixed(2)}</span>
          </div>

          <div className="flex flex-row justify-between">
            <span className="text-muted">Shipping</span>
            <span>Free</span>
          </div>

          <div className="border-b"></div>

          <div className="flex flex-row justify-between font-bold">
            <span>Total</span>
            <span className="total-price">${subtotal.toFixed(2)}</span>
          </div>

          <button
            onClick={() => navigate("/checkout")}
            className="checkout-btn"
          >
            Proceed to Checkout
          </button>

          <button className="clear-cart-btn" onClick={() => setCart([])}>
            Clear Cart
          </button>
        </div>
      </div>
    </div>
  );
}
