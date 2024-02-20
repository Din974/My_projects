const express = require('express');
const router = express.Router();
const db = require('../db');
const authenticateJWT = require('../authMiddleware');

router.get('/products', (req, res) => {
  db.query('SELECT * FROM products', (err, results) => {
    if (err) {
      console.error('Error retrieving products:', err);
      res.status(500).json({ error: 'Server error' });
    } else {
      res.json(results);
    }
  });
});

router.get('/products/:id', (req, res) => {
  const productId = req.params.id;
  db.query('SELECT * FROM products WHERE id = ?', [productId], (err, results) => {
    if (err) {
      console.error('Error retrieving product details:', err);
      res.status(500).json({ error: 'Server error' });
    } else if (results.length === 0) {
      res.status(404).json({ error: 'Product not found' });
    } else {
      res.json(results[0]);
    }
  });
});

router.post('/products', authenticateJWT, (req, res) => {
  if (req.user.role !== 'ADMIN') {
    return res.status(403).json({ error: 'Forbidden - Insufficient permissions' });
  }

  const { name, description, price } = req.body;
  db.query('INSERT INTO products (name, description, price) VALUES (?, ?, ?)', [name, description, price], (err, results) => {
    if (err) {
      console.error('Error creating the product:', err);
      res.status(500).json({ error: 'Server error' });
    } else {
      res.json({ message: 'Product created successfully', productId: results.insertId });
    }
  });
});

router.put('/products/:id', authenticateJWT, (req, res) => {
  if (req.user.role !== 'ADMIN') {
    return res.status(403).json({ error: 'Forbidden - Insufficient permissions' });
  }

  const productId = req.params.id;
  const { name, description, price } = req.body;
  db.query('UPDATE products SET name = ?, description = ?, price = ? WHERE id = ?', [name, description, price, productId], (err, results) => {
    if (err) {
      console.error('Error updating the product:', err);
      res.status(500).json({ error: 'Server error' });
    } else if (results.affectedRows === 0) {
      res.status(404).json({ error: 'Product not found' });
    } else {
      res.json({ message: 'Product updated successfully' });
    }
  });
});

router.delete('/products/:id', authenticateJWT, (req, res) => {
  if (req.user.role !== 'ADMIN') {
    return res.status(403).json({ error: 'Forbidden - Insufficient permissions' });
  }

  const productId = req.params.id;
  db.query('DELETE FROM products WHERE id = ?', [productId], (err, results) => {
    if (err) {
      console.error('Error deleting the product:', err);
      res.status(500).json({ error: 'Server error' });
    } else if (results.affectedRows === 0) {
      res.status(404).json({ error: 'Product not found' });
    } else {
      res.json({ message: 'Product deleted successfully' });
    }
  });
});

module.exports = router;
