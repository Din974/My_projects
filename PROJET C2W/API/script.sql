CREATE TABLE users (
    id INT PRIMARY KEY,
    username VARCHAR(255) NOT NULL,
    password VARCHAR(255) NOT NULL,
    role VARCHAR(50) NOT NULL
);

INSERT INTO users (id, username, password, role)
VALUES
    (1, 'admin', 'adminpassword', 'ADMIN'),
    (2, 'utilisateur', 'userpassword', 'USER');

CREATE TABLE product (
    id INT PRIMARY KEY,
    name VARCHAR(255) NOT NULL,
    description TEXT,
    price DECIMAL(10, 2) NOT NULL
);

INSERT INTO product (id, name, description, price)
VALUES
    (1, 'Produit 1', 'Description du Produit 1', 19.99),
    (2, 'Produit 2', 'Description du Produit 2', 29.99);
