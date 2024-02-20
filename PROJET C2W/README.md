# PROJET C2W

PROJET C2W est une API en Node.js qui permet d'exécuter différentes requêtes CRUD sur un produit choisi par l'utilisateur. Pour effectuer certaines actions, l'utilisateur doit se connecter et être administrateur. La base de données choisie est MySQL.

## Installation

Avant de pouvoir exécuter le projet, assurez-vous d'avoir Node.js et MySQL installés sur votre système.

1. Accédez au répertoire du projet :

```bash
cd PROJET-C2W
```

2. Installez les dépendances en utilisant npm :

```bash
npm install
```

## Configuration de la base de données

Assurez-vous d'avoir une base de données MySQL prête à être utilisée. Vous devrez configurer les informations de connexion à la base de données dans le fichier API/app/db.js.

```js
const dbConfig = {
  host: 'localhost',
  user: 'votre_utilisateur',
  password: 'votre_mot_de_passe',
  database: 'votre_base_de_données',
};
```

## Tests

Pour tester les API, vous pouvez utiliser des applications telles que Postman. Deux collections Postman sont fournies avec ce projet :

1. Collection CRUD sur les produits : PROJET-C2W/API/Products Management.postman_collection.json
2. Collection CRUD sur les utilisateurs : PROJET-C2W/API/Users Management.postman_collection.json

Importez ces collections dans Postman pour effectuer des tests sur les API.

Je vous prie de m'excuser pour toute confusion précédente. Si vous avez d'autres questions ou besoin d'autres modifications, n'hésitez pas à me le faire savoir !


