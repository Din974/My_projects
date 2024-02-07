# Projet Stormtroopers

## Introduction

Ce projet implémente une fonction `stormtroopers` qui prend une liste d'entiers `numbers` en entrée et retourne une liste contenant uniquement les entiers uniques de la liste d'origine.

### Fonctionnement de l'algorithme

La fonction `stormtroopers` suit les étapes suivantes :

1. **Initialisation :** Une liste vide `res` est créée pour stocker les entiers uniques.

2. **Parcours de la liste :** Une boucle externe parcourt chaque entier de la liste `numbers`.

3. **Vérification des entiers uniques :** Pour chaque entier `numbers[i]`, la fonction compte combien de fois cet entier apparaît dans la liste `numbers`. Si cet entier apparaît exactement une fois dans la liste et n'est pas déjà présent dans la liste `res`, il est ajouté à la liste `res`.

4. **Renvoi de la liste :** La liste `res` contenant les entiers uniques est renvoyée à la fin de la fonction.

#### Complexité algorithmique

La complexité de cet algorithme est de l'ordre de O(n^2), où n est la longueur de la liste `numbers`. Cela est dû à la double boucle qui compare chaque entier avec tous les autres entiers de la liste.

##### Utilisation

La fonction `stormtroopers` peut être utilisée comme suit dans un script Python :

```python
numbers = [1, 2, 2, 3, 4, 4, 5]
result = stormtroopers(numbers)
print(result)
```

Dans cet exemple, la fonction retournera la liste [1, 3, 5] contenant uniquement les entiers uniques de la liste d'origine.