import { useState, useEffect } from "react";
import "./App.css";
import toast, { Toaster } from "react-hot-toast";

function App() {
  const API_URL = "/books";

  const [books, setBooks] = useState([]);
  const [form, setForm] = useState({
    id: "",
    title: "",
    author: "",
  });

  const [editingId, setEditingId] = useState(null);

  // GET: Fetch all books
  const getBooks = async () => {
    try {
      const response = await fetch(API_URL);
      if (!response.ok) throw new Error("Failed to fetch books");

      const data = await response.json();
      setBooks(data);
    } catch (error) {
      toast.error("Failed to fetch books");
    }
  };

  useEffect(() => {
    getBooks();
  }, []);

  // Handle input changes
  const handleChange = (e) => {
    setForm({
      ...form,
      [e.target.name]: e.target.value,
    });
  };

  // POST: Add book / PUT: Update book
  const handleSubmit = async (e) => {
    e.preventDefault();

    const bookData = {
      id: Number(form.id),
      title: form.title,
      author: form.author,
    };

    try {
      const url = editingId === null ? API_URL : `${API_URL}/${editingId}`;

      const method = editingId === null ? "POST" : "PUT";

      const response = await fetch(url, {
        method: method,
        headers: {
          "Content-Type": "application/json",
        },
        body: JSON.stringify(bookData),
      });

      const result = await response.json();

      if (!response.ok) {
        throw new Error(result.message || "Operation failed");
      }

      if (editingId === null) {
        toast.success("Book added successfully!");
      } else {
        toast.success("Book updated successfully!");
      }

      setForm({ id: "", title: "", author: "" });
      setEditingId(null);

      getBooks();
    } catch (error) {
      toast.error(error.message);
    }
  };

  // Load book details into form
  const editBook = async (id) => {
    try {
      const response = await fetch(`${API_URL}/${id}`);

      if (!response.ok) throw new Error("Book not found");

      const book = await response.json();

      setForm({
        id: book.id,
        title: book.title,
        author: book.author,
      });

      setEditingId(id);
    } catch (error) {
      toast.error(error.message);
    }
  };

  // DELETE: Remove book
  const deleteBook = async (id) => {
    if (!window.confirm("Are you sure you want to delete this book?")) {
      return;
    }

    try {
      const response = await fetch(`${API_URL}/${id}`, {
        method: "DELETE",
      });

      const result = await response.json();

      if (!response.ok) throw new Error(result.message);

      toast.success("Book deleted successfully!");

      if (editingId === id) {
        setEditingId(null);
        setForm({ id: "", title: "", author: "" });
      }

      getBooks();
    } catch (error) {
      toast.error(error.message);
    }
  };

  // Cancel editing
  const cancelEdit = () => {
    setEditingId(null);
    setForm({ id: "", title: "", author: "" });
  };

  return (
    <>
      <Toaster
        position="top-right"
        reverseOrder={false}
        toastOptions={{
          duration: 3000,
        }}
      />
      <div className="container">
        <h1>Book Management System</h1>

        <div className="form-container">
          <h2>{editingId === null ? "Add New Book" : "Update Book"}</h2>

          <form onSubmit={handleSubmit}>
            <input
              type="number"
              name="id"
              placeholder="Book ID"
              value={form.id}
              onChange={handleChange}
              disabled={editingId !== null}
              required
            />

            <input
              type="text"
              name="title"
              placeholder="Book Title"
              value={form.title}
              onChange={handleChange}
              required
            />

            <input
              type="text"
              name="author"
              placeholder="Author Name"
              value={form.author}
              onChange={handleChange}
              required
            />

            <button type="submit">
              {editingId === null ? "Add Book" : "Update Book"}
            </button>

            {editingId !== null && (
              <button type="button" onClick={cancelEdit}>
                Cancel
              </button>
            )}
          </form>
        </div>

        <div className="books-container">
          <h2>All Books</h2>

          <table>
            <thead>
              <tr>
                <th>ID</th>
                <th>Title</th>
                <th>Author</th>
                <th>Actions</th>
              </tr>
            </thead>

            <tbody>
              {books.map((book) => (
                <tr key={book.id}>
                  <td>{book.id}</td>
                  <td>{book.title}</td>
                  <td>{book.author}</td>
                  <td>
                    <button className="edit" onClick={() => editBook(book.id)}>
                      Edit
                    </button>

                    <button
                      className="delete"
                      onClick={() => deleteBook(book.id)}
                    >
                      Delete
                    </button>
                  </td>
                </tr>
              ))}

              {books.length === 0 && (
                <tr>
                  <td colSpan="4">No books found.</td>
                </tr>
              )}
            </tbody>
          </table>
        </div>
      </div>
    </>
  );
}

export default App;
