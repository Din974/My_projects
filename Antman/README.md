# Antman

Antman est un programme écrit en C qui permet de compresser des fichiers texte.

## Compilation

Pour compiler Antman et Giantman, exécutez la commande `make` à la racine du projet. Cela générera les exécutables `antman` et `giantman`.

### Compression avec Antman

Pour compresser un fichier texte, utilisez la commande suivante à la racine du projet :

```
./antman/antman [nom du fichier à compresser] > [nom du fichier qui sera créé]
```

Par exemple : ./antman/antman lyr1.txt > texte_compressé.txt

Dans ce cas là le fichier texte_compressé.txt contiendra le fichier lyr1.txt compressé

### Décompression avec Giantman

Pour décompresser un fichier compressé par Antman, utilisez la commande suivante à la racine du projet :

```
./giantman/giantman [nom du fichier à décompresser] (> [nom du fichier qui sera créé])
```

Par exemple : ./giantman/giantman texte_compressé.txt (> texte_decompressé.txt)

Dans ce cas là le fichier texte_décompressé.txt contiendra le fichier texte_compressé.txt décompressé

Si vous ne spécifiez pas le nom du fichier qui sera créé lors de la décompression, le contenu de la décompression s'affichera dans le terminal.

N'oubliez pas de vérifier les autorisations d'exécution des fichiers Antman et Giantman si nécessaire.





