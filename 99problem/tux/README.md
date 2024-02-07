# Projet Tux

## Introduction

Ce projet implémente une fonction `tux` qui prend une liste d'entiers `numbers` en entrée et retourne l'indice du premier élément qui est un "pivot". Un pivot est défini comme un élément pour lequel tous les éléments à sa gauche sont strictement inférieurs à lui, et tous les éléments à sa droite sont supérieurs ou égaux à lui.

### Fonctionnement de l'algorithme

La fonction `tux` suit les étapes suivantes :

1. **Vérification de la liste vide :** Si la liste d'entrée `numbers` est vide, la fonction retourne immédiatement une liste vide.

2. **Vérification du premier élément :** Si tous les éléments à droite du premier élément sont supérieurs ou égaux à lui, alors le premier élément est un pivot et la fonction retourne son indice 0.

3. **Parcours de la liste :** Une boucle externe parcourt chaque élément de la liste `numbers` à partir du deuxième élément.

4. **Vérification en tant que pivot :** Pour chaque élément, la fonction vérifie s'il est supérieur à son précédent. Si oui, elle vérifie ensuite si tous les éléments à sa droite sont supérieurs ou égaux à lui et que tous les éléments à sa gauche sont strictement inferieur à lui. Si c'est le cas, cet élément est un pivot et son indice est retourné.

5. **Renvoi de l'indice du pivot :** Si un pivot est trouvé, son indice est retourné. Sinon, la fonction retourne -1.

#### Complexité algorithmique

La complexité de cet algorithme est de l'ordre de O(n^2), où n est la longueur de la liste `numbers`. Cela est dû à la double boucle qui compare chaque élément avec tous les autres éléments de la liste.

##### Utilisation

La fonction `tux` peut être utilisée comme suit dans un script Python :

```python
from typing import List

numbers = [100, 97, 101, 109, 111, 110]
result = tux(numbers)
print(result)
```

Dans cet exemple, la fonction retournera 2, car 101 est le premier pivot dans la liste.
