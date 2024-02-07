# Projet Daemon

## Introduction
Ce projet implémente une fonction daemon qui prend une liste d'entiers et un indice k en tant qu'arguments et retourne un booléen. La fonction vise à vérifier une condition particulière dans la sous-liste de numbers délimitée par l'indice k.

### Fonctionnement de l'algorithme

L'algorithme suit une approche de vérification ascendante et descendante à partir de l'indice k dans la liste numbers. Voici comment l'algorithme fonctionne :

Parcourir la sous-liste de numbers de l'indice 0 à l'indice k - 1 inclus.

Si un nombre dans cette partie est supérieur ou égal à numbers[k], la fonction retourne False.
Parcourir la sous-liste de numbers de l'indice k jusqu'à la fin de la liste.

Si un nombre dans cette partie est strictement inférieur à numbers[k], la fonction retourne False.
Si aucune des conditions n'est vérifiée, la fonction retourne True.

#### Complexité algorithmique

La complexité de cet algorithme peut être analysée comme suit :

La première boucle parcourt les éléments de l'indice 0 à k - 1.
La deuxième boucle parcourt les éléments de l'indice k jusqu'à la fin de la liste.
Par conséquent, la complexité totale est de l'ordre de O(k) pour la pire des cas, où k est l'indice passé en argument.

##### Utilisation
Exemple d'utilisation de la fonction daemon :

```python
from typing import List

numbers = [1, 3, 5, 2, 7, 9]
k = 3

result = daemon(numbers, k)
print(result)
```

N'hésitez pas à nous contacter si vous avez des questions ou des préoccupations.