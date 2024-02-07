# Projet Playset

## Introduction

Ce projet implémente une fonction `playset` qui prend une chaîne de caractères `s` en entrée et retourne `True` si au moins deux caractères identiques se trouvent dans la chaîne, sinon `False`.

### Fonctionnement de l'algorithme

La fonction `playset` suit les étapes suivantes :

1. **Parcours de la chaîne :** Une boucle parcourt chaque caractère de la chaîne `s`.

2. **Vérification des doublons :** Pour chaque caractère, la fonction vérifie s'il existe un caractère identique dans le reste de la chaîne. Si un doublon est trouvé, la fonction retourne `True`.

3. **Aucun doublon trouvé :** Si la boucle se termine sans trouver de doublon, la fonction retourne `False`.

#### Complexité algorithmique

La complexité de la fonction `playset` est de l'ordre de O(n^2), où n est la longueur de la chaîne `s`. Cela est dû à la double boucle qui compare chaque caractère avec tous les autres caractères de la chaîne.

##### Utilisation

La fonction `playset` peut être utilisée comme suit dans un script Python :

```python
s = "abcdeedcba"
result = playset(s)
print(result)
```

Dans cet exemple, la chaîne "abcdeedcba" contient des caractères identiques, donc la fonction retournera True.