# Projet Roger Rabbit

## Introduction

Ce projet implémente une fonction `roger_rabbit` qui prend un entier `n` en entrée et retourne une liste de chaînes de caractères représentant les nombres binaires de 1 à `n`.

### Fonctionnement de l'algorithme

La fonction `roger_rabbit` suit les étapes suivantes :

1. **Initialisation :** Une liste vide `res` est créée pour stocker les nombres binaires.

2. **Parcours des entiers :** Une boucle `for` parcourt tous les entiers de 1 à `n`.

3. **Conversion en binaire :** Pour chaque entier, il est converti en binaire en utilisant la fonction `conv_to_bin`.

4. **Ajout à la liste :** Le résultat de la conversion en binaire est ajouté à la liste `res`.

5. **Renvoi de la liste :** La liste `res` contenant les nombres binaires est renvoyée à la fin de la fonction.

#### Complexité algorithmique

La complexité de cet algorithme est de l'ordre de O(n), où n est la valeur de l'entier `n`. Cela est dû au fait que chaque entier de 1 à `n` est parcouru une seule fois.

##### Utilisation

Exemple d'utilisation de la fonction `roger_rabbit` :

```python
n = 5
result = roger_rabbit(n)
print(result)
```

Dans cet exemple, la fonction retournera la liste ['1', '10', '11', '100', '101'] représentant les nombres binaires de 1 à 5.