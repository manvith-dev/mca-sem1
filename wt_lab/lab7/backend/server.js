const express = require('express');

const app = express();

const PORT = 5000;

const fs = require('fs');

app.use(express.json());

// Home route
app.get('/', (req, res) => {
    res.send('Express Server is Running!');
});

app.get('/books', (req, res) => {
    const data = fs.readFileSync('books.json', 'utf-8');
    const books = JSON.parse(data);
    res.json(books);
});

app.get('/books/:id', (req, res) => {
    const id = req.params.id;
    const data = fs.readFileSync('books.json', 'utf-8');
    const books = JSON.parse(data);

    for (let i = 0; i < books.length; i++) {
        if (books[i].id == id) {
            res.json(books[i]);
            return;
        }
    }

    res.status(404).json({ error: "Book not found" });
})

app.post('/books', (req, res) => {
    try {

        const newBooks = req.body;

        const data = fs.readFileSync('books.json', 'utf-8');
        const books = JSON.parse(data);
        books.push(newBooks);
        fs.writeFileSync('books.json', JSON.stringify(books, null, 4));
        res.json({ message: "Books added successfully." });
    } catch (error) {
        res.status(500).json({
            message: "Something went wrong",
            error: error.message
        })
    }
})

app.put('/books/:id', (req, res) => {
    try {

        const id = req.params.id;
        const bookData = req.body;

        const data = fs.readFileSync('books.json', 'utf-8');
        let books = JSON.parse(data);
        let bookFound = false;
        for (let i = 0; i < books.length; i++) {
            if (books[i].id == id) {
                books[i] = { ...bookData, id: books[i].id };
                bookFound = true;
                break;
            }
        }

        if (!bookFound) {
            return res.status(404).json({
                message: "Book not found"
            });
        }

        fs.writeFileSync('books.json', JSON.stringify(books, null, 4));
        res.json({ message: "Books updated  successfully." });

    } catch (error) {
        res.status(500).json({
            message: "Something went wrong",
            error: error.message
        });
    }
});

app.delete('/books/:id', (req, res) => {
    try {

        const id = req.params.id;
        const data = fs.readFileSync('books.json', 'utf-8');

        let books = JSON.parse(data);
        let newBooks = [];
        let bookFound = false;

        for (let i = 0; i < books.length; i++) {
            if (books[i].id == id) {
                bookFound = true;
            } else {
                newBooks.push(books[i]);
            }
        }

        if (!bookFound) {
            return res.status(404).json({
                message: "Book not found"
            });
        }

        fs.writeFileSync('books.json', JSON.stringify(newBooks, null, 4));
        res.json({ message: "Books deleted successfully." });

    } catch (error) {
        res.status(500).json({
            message: "Something went wrong",
            error: error.message
        });
    }
});

app.listen(PORT, () => {
    console.log(`Server running on http://localhost:${PORT}`);
});
