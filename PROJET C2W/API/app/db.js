const mysql = require('mysql');

const dbConfig = {
  host: 'localhost',
  user: 'votre-utilisateur',
  password: 'votre-mot-de-passe',
  database: 'votre-base-de-données',
};

const connection = mysql.createConnection(dbConfig);

connection.connect((err) => {
    if (err) {
      console.error('Error connecting to MySQL:', err);
    } else {
      console.log('Connected to MySQL');

      connection.query(`
        CREATE TABLE IF NOT EXISTS products (
          id INT PRIMARY KEY AUTO_INCREMENT,
          name VARCHAR(255) NOT NULL,
          description TEXT NOT NULL,
          price DECIMAL(10, 2) NOT NULL
        );
      `, (err) => {
        if (err) {
          console.error('Error creating the products table:', err);
        } else {
          console.log('Products table created successfully');
        }
      });

      connection.query(`
        CREATE TABLE IF NOT EXISTS users (
          id INT PRIMARY KEY AUTO_INCREMENT,
          username VARCHAR(255) NOT NULL UNIQUE,
          password VARCHAR(255) NOT NULL,
          role ENUM('USER', 'ADMIN') DEFAULT 'USER'
        );
      `, (err) => {
        if (err) {
          console.error('Error creating the users table:', err);
        } else {
          console.log('Users table created successfully');
        }
      });
    }
  });

module.exports = connection;
