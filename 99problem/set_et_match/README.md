# Projet Set et Match

## Introduction

Ce projet implémente une fonction `set_et_match` qui prend une liste d'entiers `numbers` et un entier `n` en entrée, et retourne `True` si deux nombres distincts de la liste ont une somme égale à `n`, sinon `False`.

### Fonctionnement de l'algorithme

La fonction `set_et_match` suit les étapes suivantes :

1. **Initialisation :** Création d'une liste vide `check` pour stocker les nombres déjà vérifiés.

2. **Parcours de la liste :** Une boucle externe parcourt chaque nombre de la liste `numbers`.

3. **Vérification de la somme :** Pour chaque nombre `nb`, la fonction calcule le complément `nb_to_search` en soustrayant `nb` de `n`. Ensuite, elle vérifie si ce complément est présent dans la liste `check`. Si c'est le cas, cela signifie qu'il existe une paire de nombres distincts dont la somme est égale à `n`, et la fonction retourne `True`. Sinon, le nombre actuel `nb` est ajouté à la liste `check`.

4. **Aucune paire trouvée :** Si la boucle se termine sans trouver de paire de nombres dont la somme est égale à `n`, la fonction retourne `False`.

#### Complexité algorithmique

La complexité de la fonction `set_et_match` est de l'ordre de O(n), où n est la longueur de la liste `numbers`. Cela est dû au parcours linéaire de la liste et à l'utilisation d'une liste pour stocker les nombres déjà vérifiés.

##### Utilisation

La fonction `set_et_match` peut être utilisée comme suit dans un script Python :

```python
numbers = [1, 2, 3, 4, 5]
n = 9
result = set_et_match(numbers, n)
print(result)
```

Dans cet exemple, la fonction retournera True car la paire de nombres [4, 5] a une somme égale à 9.