# Projet Yulaw

## Introduction

Ce projet implémente une fonction `yulaw` qui prend une chaîne de caractères `s` en entrée et retourne une nouvelle chaîne avec chaque caractère unique une seule fois, dans l'ordre de leur première occurrence.

### Fonctionnement de l'algorithme

La fonction `yulaw` suit les étapes suivantes :

1. **Initialisation :** Une chaîne vide `res` est créée pour stocker les caractères uniques.

2. **Parcours de la chaîne :** Une boucle externe parcourt chaque caractère de la chaîne `s`.

3. **Vérification des caractères uniques :** Pour chaque caractère `s[i]`, la fonction vérifie si ce caractère n'est pas déjà présent dans la chaîne `res`. Si ce n'est pas le cas, le caractère est ajouté à la chaîne `res`.

4. **Renvoi de la nouvelle chaîne :** La chaîne `res` modifiée, contenant les caractères uniques dans l'ordre de leur première occurrence, est renvoyée à la fin de la fonction.

### Complexité algorithmique

La complexité de la fonction `yulaw` est de l'ordre de O(n^2), où n est la longueur de la chaîne `s`. Cette complexité résulte de la boucle qui parcourt chaque caractère de la chaîne et de l'appel à `res.count(s[i])` qui parcourt également la chaîne à chaque itération.

### Utilisation

La fonction `yulaw` peut être utilisée comme suit dans un script Python :

```python
s = "abacabad"
result = yulaw(s)
print(result)
```

Dans cet exemple, la fonction yulaw retournera la chaîne "abcd" car chaque caractère apparaît une seule fois dans l'ordre de leur première occurrence.