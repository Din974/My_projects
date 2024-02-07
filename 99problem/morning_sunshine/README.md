# Projet Morning Sunshine

## Introduction

Ce projet implémente une fonction `morning_sunshine` qui prend une liste d'entiers `numbers` en entrée et retourne une nouvelle liste contenant les éléments qui sont strictement plus grands que tous les éléments qui les suivent dans la liste.

### Fonctionnement de l'algorithme

L'algorithme suit les étapes suivantes :

1. **Initialisation :** Une nouvelle liste vide `new` est créée pour stocker les éléments qui répondent au critère.

2. **Vérification de la liste vide :** Si la liste d'entrée `numbers` est vide, la fonction retourne immédiatement une liste vide.

3. **Parcours de la liste :** Une boucle parcourt chaque entier de la liste `numbers` en commençant par la fin.

4. **Vérification de supériorité :** Pour chaque entier, la fonction vérifie s'il est strictement plus grand que le maximum rencontré jusqu'à présent. Si c'est le cas, il est ajouté à la liste `new`, sinon il est ignoré.

5. **Renvoi de la nouvelle liste :** La liste `new` contenant les éléments strictement plus grands que tous les éléments qui les suivent est renvoyée à la fin de la fonction.

### Complexité algorithmique

La complexité de cet algorithme est de l'ordre de O(n), où n est la longueur de la liste `numbers`. Cela est dû à une seule boucle parcourant les éléments de la liste.

### Utilisation

La fonction `morning_sunshine` peut être utilisée comme suit dans un script Python :

```python
numbers = [4, 2, 7, 1, 5, 9]
result = morning_sunshine(numbers)
print(result)
```

Dans cet exemple, la liste [4, 2, 7, 1, 5, 9] sera transformée pour ne contenir que les éléments strictement plus grands que tous les éléments qui les suivent.
