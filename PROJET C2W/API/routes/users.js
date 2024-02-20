// routes/users.js
const express = require('express');
const router = express.Router();
const db = require('../db');
const bcrypt = require('bcrypt');
const jwt = require('jsonwebtoken');
const authenticateJWT = require('../authMiddleware');

router.post('/login', (req, res) => {
  const { username, password } = req.body;

  console.log('Attempting to log in with username:', username);

  // Assuming you have a 'users' table with the mentioned structure
  db.query('SELECT * FROM users WHERE username = ?', [username], (err, results) => {
    if (err) {
      console.error('Error retrieving user:', err);
      res.status(500).json({ error: 'Server error' });
    } else if (results.length === 0) {
      res.status(401).json({ error: 'Unauthorized - Invalid credentials' });
    } else {
      const user = results[0];

      // Compare hashed passwords using bcrypt
      bcrypt.compare(password, user.password, (bcryptErr, result) => {
        if (!result || bcryptErr) {
            console.error('Error comparing passwords:', bcryptErr);
            res.status(401).json({ error: 'Unauthorized - Invalid credentials' });
        } else {
            const jwtSecret = process.env.JWT_SECRET || 'KKK974';
            const token = jwt.sign({ username: user.username, role: user.role }, jwtSecret, { expiresIn: '1h' });
            res.json({ token });
        }
      });
    }
  });
});

// GET /users - Retrieve the list of all users (accessible to the admin)
router.get('/users', authenticateJWT, (req, res) => {
  // Check if the user has the "ADMIN" role
  if (req.user.role !== 'ADMIN') {
    return res.status(403).json({ error: 'Forbidden - Insufficient permissions' });
  }

  db.query('SELECT * FROM users', (err, results) => {
    if (err) {
      console.error('Error retrieving users:', err);
      res.status(500).json({ error: 'Server error' });
    } else {
      res.json(results);
    }
  });
});

// GET /users/:id - Retrieve the details of a user by their ID (accessible to the admin or the user itself)
router.get('/users/:id', authenticateJWT, (req, res) => {
  // Check if the user has the "ADMIN" role or is the user itself
  if (req.user.role !== 'ADMIN' && req.user.id !== req.params.id) {
    return res.status(403).json({ error: 'Forbidden - Insufficient permissions' });
  }

  const userId = req.params.id;
  db.query('SELECT * FROM users WHERE id = ?', [userId], (err, results) => {
    if (err) {
      console.error('Error retrieving user details:', err);
      res.status(500).json({ error: 'Server error' });
    } else if (results.length === 0) {
      res.status(404).json({ error: 'User not found' });
    } else {
      res.json(results[0]);
    }
  });
});

// POST /users - Create a new user (accessible to all, but only admin can create an admin)
router.post('/users', authenticateJWT, (req, res) => {
  // Get information from the request
  const { username, password, role } = req.body;
  // Check if the user creating the account is an admin
  const creatingUserIsAdmin = req.user.role === 'ADMIN';
  // If the user creating the account is an admin and the role is specified, use that role, otherwise, use 'USER'
  const newUserRole = creatingUserIsAdmin && role ? role : 'USER';

  // Hash the password
  bcrypt.hash(password, 10, (err, hashedPassword) => {
    if (err) {
      console.error('Error hashing the password:', err);
      res.status(500).json({ error: 'Server error' });
    } else {
      // Insert the new user into the database
      db.query('INSERT INTO users (username, password, role) VALUES (?, ?, ?)', [username, hashedPassword, newUserRole], (err, results) => {
        if (err) {
          console.error('Error creating the user:', err);
          res.status(500).json({ error: 'Server error' });
        } else {
          res.json({ message: 'User created successfully', userId: results.insertId });
        }
      });
    }
  });
});


// PUT /users/:id - Update a user by their ID (accessible to the admin or the user itself)
router.put('/users/:id', authenticateJWT, (req, res) => {
  // Check if the user has the "ADMIN" role or is the user itself
  if (req.user.role !== 'ADMIN' && req.user.id !== req.params.id) {
    return res.status(403).json({ error: 'Forbidden - Insufficient permissions' });
  }

  const userId = req.params.id;
  const { username, password } = req.body;
  bcrypt.hash(password, 10, (err, hashedPassword) => {
    if (err) {
      console.error('Error hashing the password:', err);
      res.status(500).json({ error: 'Server error' });
    } else {
      db.query('UPDATE users SET username = ?, password = ? WHERE id = ?', [username, hashedPassword, userId], (err, results) => {
        if (err) {
          console.error('Error updating the user:', err);
          res.status(500).json({ error: 'Server error' });
        } else if (results.affectedRows === 0) {
          res.status(404).json({ error: 'User not found' });
        } else {
          res.json({ message: 'User updated successfully' });
        }
      });
    }
  });
});

// DELETE /users/:id - Delete a user by their ID (accessible to the admin or the user itself)
router.delete('/users/:id', authenticateJWT, (req, res) => {
  // Check if the user has the "ADMIN" role or is the user itself
  if (req.user.role !== 'ADMIN' && req.user.id !== req.params.id) {
    return res.status(403).json({ error: 'Forbidden - Insufficient permissions' });
  }

  const userId = req.params.id;
  db.query('DELETE FROM users WHERE id = ?', [userId], (err, results) => {
    if (err) {
      console.error('Error deleting the user:', err);
      res.status(500).json({ error: 'Server error' });
    } else if (results.affectedRows === 0) {
      res.status(404).json({ error: 'User not found' });
    } else {
      res.json({ message: 'User deleted successfully' });
    }
  });
});

module.exports = router;
