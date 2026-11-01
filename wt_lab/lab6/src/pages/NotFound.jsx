/*
 * Tool Used: ChatGPT
 * Purpose: Generate checkout page
 * Prompts Used: "Give me a simple order confirmed page which accepts the data as function args and renders the page accordingly, I want it on a separate page what is the procedure"
 * Personal Verification & Edits: The code follows standard react practices.
 */ import { useNavigate } from "react-router-dom";

export default function NotFound() {
  const navigate = useNavigate();

  return (
    <div className="not-found">
      <h1>404</h1>
      <h2>Page Not Found</h2>
      <p>The page you're looking for doesn't exist.</p>

      <button onClick={() => navigate("/")}>Back to Home</button>
    </div>
  );
}
