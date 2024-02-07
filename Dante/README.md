# Dante's Star

Dante's Star est un projet composé de deux composants principaux : `generator` et `solver`. Ce README fournit un aperçu de la compilation et de l'utilisation de chaque partie du projet.

## Compilation

Pour compiler le projet, rendez-vous dans le répertoire racine et exécutez la commande suivante :

```bash
make
```

## Générateur

Le composant `generator` crée un labyrinthe en fonction des dimensions spécifiées et indique s'il doit être parfait ou imparfait.

### Utilisation

```bash
./generator/generator [x] [y] [parfait/imparfait] (> [nom du fichier de sortie] - facultatif)
```

- `[x]` : Largeur du labyrinthe.
- `[y]` : Hauteur du labyrinthe.
- `[parfait/imparfait]` : Spécifiez si le labyrinthe doit être parfait (n'ayant qu'une seule solution) ou imparfait (ayant plusieurs solutions).
- `[nom du fichier de sortie]` : Paramètre facultatif pour spécifier le nom du fichier de sortie. Si non fourni, le labyrinthe sera affiché sur stdout.

### Représentation du Labyrinthe

- `*` : Représente les espaces vides à l'intérieur du labyrinthe.
- `X` : Indique les murs dans le labyrinthe.

## Solveur

Le composant `solver` résout un labyrinthe fourni dans le format correct et détermine s'il est résoluble.

### Utilisation

```bash
./solver/solver [fichier du labyrinthe]
```

- `[fichier du labyrinthe]` : Chemin vers le fichier contenant le labyrinthe à résoudre.

### Format du Labyrinthe

Le fichier de labyrinthe d'entrée doit respecter le format suivant :

- `*` : Représente les espaces vides à l'intérieur du labyrinthe.
- `X` : Indique les murs dans le labyrinthe.

Si le labyrinthe est résoluble, le solveur fournira la solution. Sinon, il retournera un code de sortie 84.

## Exemple

Voici un exemple rapide illustrant comment utiliser les deux composants :

1. Générer un labyrinthe :

```bash
./generator/generator 10 10 parfait > labyrinthe.txt
```

2. Résoudre le labyrinthe généré :

```bash
./solver/solver labyrinthe.txt
```

## Remarque

Assurez-vous d'avoir les autorisations appropriées pour exécuter les binaires et que les dépendances nécessaires sont installées. Pour plus de détails, consultez la documentation respective de chaque composant.

Amusez-vous à explorer Dante's Star! 🌟
