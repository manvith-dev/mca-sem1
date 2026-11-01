/*
 * Tool Used: ChatGPT
 * Purpose: Generate UI for data
 * Prompts Used: "https://chatgpt.com/s/t_6ae6cb48382c8191868a461f4d59821e"
 * Personal Verification & Edits: The code follows standard react practices.
 */

import { useParams } from "react-router-dom";
import { useEffect, useState } from "react";
import Product from "../components/Product";

export default function ProductPage() {
  const { id } = useParams();
  const [product, setProduct] = useState(null);

  useEffect(() => {
    async function fetchProduct() {
      const res = await fetch(`https://dummyjson.com/products/${id}`);

      const data = await res.json();
      setProduct(data);
    }

    fetchProduct();
  }, [id]);

  if (!product) return <p>Loading...</p>;

  return <Product product={product} />;
}
