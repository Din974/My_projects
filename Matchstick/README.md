# README - Projet Matchstick

## Description
Le projet Matchstick est une reproduction du jeu des allumettes où le joueur affronte une intelligence artificielle. Le but du jeu est de retirer des allumettes à tour de rôle, et le joueur qui retire la dernière allumette perd la partie.

## Lancement du Projet
Suivez ces instructions pour lancer le projet :

1. Assurez-vous d'avoir `make` installé sur votre système.
2. Placez-vous à la racine du projet.
3. Utilisez la commande `make` pour compiler le projet.

```bash
make
```

4. Une fois la compilation terminée, exécutez le programme en spécifiant la taille du plateau de jeu et le nombre maximum d'allumettes que le joueur peut retirer en une fois.

```bash
./matchstick [size] [nombre d'allumettes maximum]
```

Remplacez `[size]` par la taille souhaitée du plateau de jeu et `[nombre d'allumettes maximum]` par le nombre maximum d'allumettes que le joueur peut retirer en une seule fois.

## Exemple d'Exécution
Supposons que vous souhaitez jouer sur un plateau de taille 5 avec un maximum de 3 allumettes que le joueur peut retirer à chaque tour, vous exécuteriez la commande suivante :

```bash
./matchstick 5 3
```
