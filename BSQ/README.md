# BSQ (Biggest SQuare)

## Description
BSQ est un programme qui résout le problème de recherche de la plus grande sous-zone carrée dans une grille binaire.

## Utilisation
1. Pour compiler le programme, exécutez `make` à la racine du projet.
2. Pour exécuter le programme, utilisez la commande suivante :

```bash
./bsq [map]
```

- `[map]` est le chemin vers le fichier contenant la carte à analyser.
- La carte doit être au format spécifié ci-dessous.

## Format de la carte
- La carte doit être un fichier texte.
- La première ligne du fichier doit contenir le nombre de lignes de la carte, suivi d'un saut à la ligne.
- Le reste du fichier doit contenir la carte elle-même, avec les caractères suivants :
- '.' pour les emplacements vides.
- 'o' pour les obstacles.
- La carte doit être composée de lignes de même longueur.
- Exemple de carte valide :

```
6
.....o
.....o
......
....o.
......
......
```


## Erreurs
- Si la carte n'est pas conforme au format spécifié, le programme retournera un code d'erreur 84.
