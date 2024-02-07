# Projet Falafel

## Introduction

Ce projet implémente une fonction `falafel` qui vérifie si une chaîne de caractères `s` peut être transformée en un palindrome. La fonction retourne True si c'est possible, sinon False.

### Fonctionnement de l'algorithme

La fonction `falafel` suit les étapes suivantes :

1. **Initialisation :** La variable `unpair` est utilisée pour stocker le caractère qui apparaît un nombre impair de fois dans la chaîne `s`. La variable `check` est utilisée pour suivre si un caractère avec un nombre impair d'occurrences a déjà été rencontré.

2. **Parcours de la chaîne :** La boucle parcourt chaque caractère de la chaîne `s`.

3. **Vérification des caractères uniques :** Pour chaque caractère `char` dans la chaîne `s`, on vérifie si le nombre d'occurrences de ce caractère dans la chaîne est impair. Si c'est le cas et qu'aucun caractère avec un nombre impair d'occurrences n'a été rencontré auparavant, on met à jour la variable `unpair` avec ce caractère et on met `check` à True. Si un caractère avec un nombre impair d'occurrences a déjà été rencontré et que le caractère actuel est différent de `unpair`, la fonction retourne False.

4. **Vérification finale :** À la fin du parcours de la chaîne, si un caractère avec un nombre impair d'occurrences a été rencontré, la fonction retourne True, sinon False.

### Complexité algorithmique

La complexité de cet algorithme est de l'ordre de O(n), où n est la longueur de la chaîne `s`. Cela est dû au parcours linéaire de la chaîne pour vérifier les occurrences des caractères.

### Utilisation

Exemple d'utilisation de la fonction `falafel` :

```python
s = "radar"
result = falafel(s)
print(result)
```

Dans cet exemple, la fonction retournera True car la chaîne "radar" est un palindrome.
