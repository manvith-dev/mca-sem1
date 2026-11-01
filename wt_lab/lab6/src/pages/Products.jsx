/*
 * Tool Used: ChatGPT
 * Purpose: Generate UI for data
 * Prompts Used: "https://chatgpt.com/s/t_6ae6cb48382c8191868a461f4d59821e"
 * Personal Verification & Edits: The code follows standard react practices.
 */

import { useState, useEffect } from "react";
import { H1, H3, Muted } from "../components/Typography";
import { Link } from "react-router-dom";

export default function Products() {
  const [products, setProducts] = useState([]);
  const [fetchLink, setFetchLink] = useState("https://dummyjson.com/products");
  const [categories, setCategories] = useState([]);

  useEffect(() => {
    async function fetchProducts() {
      try {
        const res = await fetch(fetchLink);
        const data = await res.json();
        setProducts(data.products);
      } catch {
        console.log("Error");
      }
    }
    fetchProducts();
  }, [fetchLink]);

  useEffect(() => {
    async function fetchCategories() {
      try {
        const res = await fetch("https://dummyjson.com/products/categories");
        const data = await res.json();
        console.log(data);
        setCategories(data);
      } catch {
        console.log("Error");
      }
    }
    fetchCategories();
  }, []);

  return (
    <div className="flex flex-col gap-4 p-2 items-center justify-center">
      <H1>All Products</H1>
      <div className="flex flex-row gap-2">
        <div className="flex flex-col">
          {categories.map((category) => (
            <button
              key={category.slug}
              onClick={() => {
                setFetchLink(category.url);
              }}
              className="flex gap-1 filter-btn"
            >
              <input
                type="radio"
                name="category"
                checked={category.url == fetchLink}
                readOnly
              />
              <div>{category.slug}</div>
            </button>
          ))}
        </div>
        <div className="divider"></div>
        <div className="grid grid-cols-3 gap-2">
          {products.map((product) => (
            <Link to={"/product/" + product.id} className="no-link-decoration">
              <ProductCards
                key={product.id}
                imageUrl={product.thumbnail}
                price={product.price}
                title={product.title}
                description={product.description}
              />
            </Link>
          ))}
        </div>
      </div>
    </div>
  );
}

function ProductCards({ imageUrl, title, price, description }) {
  return (
    <div className="flex flex-col border rounded-md p-2 product-card gap-1">
      <ProductImage src={imageUrl} />
      <ProductTitle>{title}</ProductTitle>
      <ProductPrice price={price} />
      <ProductDescription className="text-xs">{description}</ProductDescription>
    </div>
  );
}

function ProductImage({ src, children }) {
  return <img src={src} className="product-image" />;
}

function ProductTitle({ children }) {
  return <H3>{children}</H3>;
}

function ProductDescription({ className, children }) {
  return <Muted className={className}>{children}</Muted>;
}

function ProductPrice({ price }) {
  return <p className="font-bold">$ {price}</p>;
}
