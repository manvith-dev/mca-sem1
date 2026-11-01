/*
 * Tool Used: ChatGPT
 * Purpose: Generate UI for data
 * Prompts Used: "https://chatgpt.com/s/t_6ae6cb48382c8191868a461f4d59821e"
 * Personal Verification & Edits: The code follows standard react practices.
 */

import { useState } from "react";

export default function Product({ product }) {
  const [selectedImage, setSelectedImage] = useState(product.thumbnail);

  const originalPrice = (
    product.price /
    (1 - product.discountPercentage / 100)
  ).toFixed(2);

  return (
    <div className="product-page flex flex-col gap-2 w-full p-2">
      {/* Breadcrumb */}
      <div className="breadcrumb text-muted">
        Home / {product.category} / {product.title}
      </div>

      {/* Main Product Section */}
      <div className="product-layout flex flex-row gap-4">
        {/* Image Gallery */}
        <div className="product-gallery flex flex-col gap-1">
          <div className="product-main-image bg2 rounded-md">
            <img src={selectedImage} alt={product.title} />
          </div>

          <div className="product-thumbnails flex flex-row gap-1">
            {product.images.map((image, index) => (
              <button
                key={index}
                className={`thumbnail ${
                  selectedImage === image ? "active" : ""
                }`}
                onClick={() => setSelectedImage(image)}
              >
                <img src={image} alt={`${product.title} ${index + 1}`} />
              </button>
            ))}
          </div>
        </div>

        {/* Product Information */}
        <div className="product-info flex flex-col gap-2">
          <div className="flex flex-row items-center gap-1">
            <span className="category-tag">{product.category}</span>
            <span className="text-muted">SKU: {product.sku}</span>
          </div>

          <h1 className="product-heading">{product.title}</h1>

          <p className="text-muted">
            By <span className="text-primary font-bold">{product.brand}</span>
          </p>

          {/* Rating */}
          <div className="flex flex-row items-center gap-1">
            <span className="rating">★ {product.rating}</span>
            <span className="text-muted">
              ({product.reviews.length} reviews)
            </span>
          </div>

          <div className="border-b"></div>

          {/* Price */}
          <div className="flex flex-col gap-1">
            <div className="flex flex-row items-center gap-1">
              <h2 className="product-price">${product.price}</h2>
              <span className="old-price">${originalPrice}</span>
              <span className="discount-tag">
                {product.discountPercentage}% OFF
              </span>
            </div>

            <span className="text-muted text-xs">Inclusive of all taxes</span>
          </div>

          {/* Stock */}
          <div className="flex flex-row items-center gap-1">
            <span
              className={`stock-dot ${
                product.stock > 0 ? "in-stock" : "out-stock"
              }`}
            ></span>
            <span className="text-xs">
              {product.stock > 0
                ? `${product.stock} units available`
                : "Out of stock"}
            </span>
            <span className="availability-tag">
              {product.availabilityStatus}
            </span>
          </div>

          <p className="product-description">{product.description}</p>

          {/* Actions */}
          <div className="flex flex-row gap-1 product-actions">
            <button
              onClick={() => {
                const cart = JSON.parse(localStorage.getItem("cart") || "[]");

                const existing = cart.find((item) => item.id === product.id);

                if (existing) {
                  existing.quantity += 1;
                } else {
                  cart.push({
                    id: product.id,
                    title: product.title,
                    price: product.price,
                    thumbnail: product.thumbnail,
                    brand: product.brand,
                    category: product.category,
                    quantity: 1,
                  });
                }

                localStorage.setItem("cart", JSON.stringify(cart));
              }}
              className="add-cart-btn"
              disabled={product.stock <= 0}
            >
              Add to Cart
            </button>

            <button className="wishlist-btn">♡</button>
          </div>

          <div className="border-b"></div>

          {/* Delivery Information */}
          <div className="flex flex-col gap-1">
            <div className="detail-row">
              <span className="text-muted">Shipping</span>
              <span>{product.shippingInformation}</span>
            </div>

            <div className="detail-row">
              <span className="text-muted">Warranty</span>
              <span>{product.warrantyInformation}</span>
            </div>

            <div className="detail-row">
              <span className="text-muted">Returns</span>
              <span>{product.returnPolicy}</span>
            </div>
          </div>
        </div>
      </div>

      {/* Product Specifications */}
      <section className="product-section flex flex-col gap-2">
        <h2 className="h3-class">Product Specifications</h2>

        <div className="spec-grid">
          <div className="spec-item">
            <span className="text-muted">Brand</span>
            <span>{product.brand}</span>
          </div>

          <div className="spec-item">
            <span className="text-muted">Weight</span>
            <span>{product.weight} g</span>
          </div>

          <div className="spec-item">
            <span className="text-muted">Width</span>
            <span>{product.dimensions.width} cm</span>
          </div>

          <div className="spec-item">
            <span className="text-muted">Height</span>
            <span>{product.dimensions.height} cm</span>
          </div>

          <div className="spec-item">
            <span className="text-muted">Depth</span>
            <span>{product.dimensions.depth} cm</span>
          </div>

          <div className="spec-item">
            <span className="text-muted">Minimum Order</span>
            <span>{product.minimumOrderQuantity}</span>
          </div>
        </div>

        <div className="flex flex-row gap-1 flex-wrap">
          {product.tags.map((tag) => (
            <span key={tag} className="category-tag">
              #{tag}
            </span>
          ))}
        </div>
      </section>

      {/* Reviews */}
      <section className="product-section flex flex-col gap-2">
        <div className="flex flex-row items-center justify-between">
          <h2 className="h3-class">Customer Reviews</h2>
          <span className="rating">★ {product.rating} / 5</span>
        </div>

        {product.reviews.map((review, index) => (
          <div className="review-card flex flex-col gap-1" key={index}>
            <div className="flex flex-row items-center justify-between">
              <span className="font-bold">{review.reviewerName}</span>

              <span className="rating">
                {"★".repeat(review.rating)}
                <span className="text-muted">
                  {"★".repeat(5 - review.rating)}
                </span>
              </span>
            </div>

            <p className="text-muted text-xs">{review.comment}</p>

            <span className="text-muted review-date">
              {new Date(review.date).toLocaleDateString()}
            </span>
          </div>
        ))}
      </section>
    </div>
  );
}
