/*
 * Tool Used: ChatGPT
 * Purpose: Generate checkout page
 * Prompts Used: "write me a home page code"
 * Personal Verification & Edits: The code follows standard react practices.
 */

import { useEffect, useState } from "react";
import { useNavigate } from "react-router-dom";

export default function Home() {
  const navigate = useNavigate();

  const [products, setProducts] = useState([]);
  const [categories, setCategories] = useState([]);
  const [selectedCategory, setSelectedCategory] = useState("");
  const [loading, setLoading] = useState(true);

  // Fetch categories
  useEffect(() => {
    async function fetchCategories() {
      try {
        const res = await fetch("https://dummyjson.com/products/categories");
        const data = await res.json();
        setCategories(data);
      } catch (error) {
        console.error("Category fetch failed:", error);
      }
    }

    fetchCategories();
  }, []);

  // Fetch featured/category products
  useEffect(() => {
    async function fetchProducts() {
      setLoading(true);

      try {
        const url = selectedCategory
          ? `https://dummyjson.com/products/category/${selectedCategory}?limit=8`
          : "https://dummyjson.com/products?limit=8&sortBy=rating&order=desc";

        const res = await fetch(url);

        if (!res.ok) {
          throw new Error("Failed to fetch products");
        }

        const data = await res.json();
        setProducts(data.products ?? []);
      } catch (error) {
        console.error(error);
        setProducts([]);
      } finally {
        setLoading(false);
      }
    }

    fetchProducts();
  }, [selectedCategory]);

  // Add product to cart
  function addToCart(product) {
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
  }

  return (
    <main className="home-page flex flex-col gap-2">
      {/* Hero Section */}
      <section className="hero-section flex flex-row items-center justify-between">
        <div className="hero-content flex flex-col gap-2">
          <span className="hero-label">YOUR NEXT FAVOURITE FIND</span>

          <h1>
            Shopping made <span>simple.</span>
          </h1>

          <p className="text-muted">
            Discover products you'll love. Explore our collection and find
            something worth adding to your cart.
          </p>

          <button className="hero-btn" onClick={() => navigate("/products")}>
            Explore Products →
          </button>
        </div>

        <div className="hero-visual">
          <div className="hero-circle">
            <span>SHOP</span>
            <span className="hero-symbol">✳</span>
          </div>
        </div>
      </section>

      {/* Categories */}
      <section className="home-section flex flex-col gap-2">
        <div className="section-heading flex flex-row justify-between items-center">
          <div>
            <h2 className="h3-class">Explore Categories</h2>
            <p className="text-muted text-xs">
              Find exactly what you're looking for.
            </p>
          </div>

          <button className="text-link" onClick={() => navigate("/products")}>
            View All →
          </button>
        </div>

        <div className="category-list flex flex-row gap-1">
          <button
            className={`category-card ${
              selectedCategory === "" ? "selected" : ""
            }`}
            onClick={() => setSelectedCategory("")}
          >
            <span>✳</span>
            <span>All Products</span>
          </button>

          {categories.slice(0, 7).map((category) => (
            <button
              key={category.slug}
              className={`category-card ${
                selectedCategory === category.slug ? "selected" : ""
              }`}
              onClick={() => setSelectedCategory(category.slug)}
            >
              <span>{category.name}</span>
            </button>
          ))}
        </div>
      </section>

      {/* Products */}
      <section className="home-section flex flex-col gap-2">
        <div className="section-heading flex flex-row justify-between items-center">
          <div>
            <h2 className="h3-class">
              {selectedCategory
                ? selectedCategory.replaceAll("-", " ")
                : "Featured Products"}
            </h2>

            <p className="text-muted text-xs">
              {selectedCategory
                ? "Products from your selected category."
                : "Some of our highest-rated picks."}
            </p>
          </div>

          <button className="text-link" onClick={() => navigate("/products")}>
            View All →
          </button>
        </div>

        {loading ? (
          <p className="text-muted">Loading products...</p>
        ) : products.length === 0 ? (
          <p className="text-muted">No products found.</p>
        ) : (
          <div className="home-product-grid">
            {products.map((product) => (
              <div className="home-product-card" key={product.id}>
                <div
                  className="home-product-image"
                  onClick={() => navigate(`/products/${product.id}`)}
                >
                  <img src={product.thumbnail} alt={product.title} />

                  <span className="product-discount">
                    -{Math.round(product.discountPercentage)}%
                  </span>
                </div>

                <div className="home-product-info flex flex-col gap-1">
                  <span className="text-muted text-xs">
                    {product.brand || product.category}
                  </span>

                  <h3 onClick={() => navigate(`/products/${product.id}`)}>
                    {product.title}
                  </h3>

                  <div className="flex flex-row items-center justify-between">
                    <span className="home-price">${product.price}</span>

                    <span className="rating">★ {product.rating}</span>
                  </div>

                  <button
                    className="home-add-btn"
                    disabled={product.stock <= 0}
                    onClick={() => addToCart(product)}
                  >
                    {product.stock > 0 ? "Add to Cart +" : "Out of Stock"}
                  </button>
                </div>
              </div>
            ))}
          </div>
        )}
      </section>

      {/* Bottom Banner */}
      <section className="bottom-banner flex flex-row justify-between items-center">
        <div className="flex flex-col gap-1">
          <h2>Found something you like?</h2>
          <p className="text-muted">Your next purchase is just a click away.</p>
        </div>

        <button className="hero-btn" onClick={() => navigate("/products")}>
          Start Shopping →
        </button>
      </section>
    </main>
  );
}
