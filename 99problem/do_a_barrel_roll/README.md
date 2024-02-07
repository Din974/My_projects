# Projet Do a Barrel Roll

## Introduction

Ce projet implémente une fonction `do_a_barrel_roll` qui effectue une rotation circulaire à gauche sur une liste d'entiers `numbers`. La rotation est effectuée k fois.

### Fonctionnement de l'algorithme

L'algorithme suit une approche de rotation circulaire à gauche. Voici comment l'algorithme fonctionne :

1. **Vérification si la liste est vide :** Si la liste est vide, la fonction retourne une liste vide.

2. **Rotation circulaire à gauche :** La fonction calcule d'abord k modulo la longueur de la liste pour s'assurer que k est dans la plage valide. Ensuite, elle effectue les rotations en utilisant le slicing pour extraire les éléments appropriés du tableau et les réorganiser.

### Complexité algorithmique

La complexité de cet algorithme est de l'ordre de O(n), où n est la taille de la liste, car la fonction effectue une seule fois la rotation circulaire en utilisant le slicing, indépendamment du nombre de rotations k.

### Utilisation

Exemple d'utilisation de la fonction `do_a_barrel_roll` :

```python
from typing import List

numbers = [1, 2, 3, 4, 5]
k = 2

result = do_a_barrel_roll(numbers, k)
print(result)
```

Dans cet exemple, la liste [1, 2, 3, 4, 5] subit une rotation circulaire à gauche de deux positions.