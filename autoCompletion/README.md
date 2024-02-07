# Autocomplétion

Ce projet permet de sélectionner une adresse parmi une liste donnée dans un fichier texte en utilisant la fonction d'autocomplétion.

## Prérequis

- Python 3.x

## Installation

1. Clonez ce dépôt dans votre répertoire local.
2. Assurez-vous d'avoir Python 3.x installé sur votre système.

## Utilisation

Exécutez le programme en utilisant la commande suivante :

```bash
python3 main.py [dictionary]
```

- `[dictionary]` est le chemin vers le fichier texte contenant le dictionnaire des adresses.

## Exemple

Supposons que le fichier texte contient les adresses suivantes :

```
Paris, 458 boulevard Saint-Germain
Paris, 343 boulevard Saint-Germain
Marseille, 343 boulevard Camille Flammarion
Marseille, 29 rue Camille Desmoulins
Marseille, 1 chemin des Aubagnens
...
```

Lorsque le programme est exécuté, il affiche les suggestions d'autocomplétion selon les entrées de l'utilisateur.

# Exemple d'exécution :

```
{m} {l} {p} {s} {t}
m
{Ma} {Mo}
a
{MARSEILLE, d} {MARSEILLE, c} {MARSEILLE, v}
d
{MARSEILLE, DEs} {MARSEILLE, DEl}
s
=> Marseille, 1 chemin des Aubagnens
```
