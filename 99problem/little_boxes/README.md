# Projet Little Boxes

## Introduction

Ce projet implémente une fonction `little_boxes` qui prend une chaîne de caractères `s` en entrée et retourne une nouvelle chaîne triant les caractères dans leur ordre ASCII.

### Fonctionnement de l'algorithme

L'algorithme utilise une approche simple en triant les caractères de la chaîne d'entrée par ordre ASCII à l'aide de la fonction `sorted()` de Python.

### Complexité algorithmique

La complexité de cet algorithme est de l'ordre de O(n * log(n)), où n est la longueur de la chaîne `s`, en raison de la fonction de tri `sorted()`. Cependant, dans le cas où les caractères de la chaîne sont limités à un ensemble fixe (comme dans la plage ASCII), la complexité peut être considérée comme linéaire.

### Utilisation

Exemple d'utilisation de la fonction `little_boxes` :

```python
s = "Hello, World! 123"
result = little_boxes(s)
print(result)
```

Dans cet exemple, la chaîne "Hello, World! 123" sera transformée pour être triée selon la valeur ASCII de chaque caractère.