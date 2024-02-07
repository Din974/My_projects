# Projet Yin Yang

## Introduction

Ce projet implémente une fonction `yin_yang` qui vérifie l'équilibre des parenthèses, crochets et accolades dans une chaîne de caractères.

### Fonctionnement de l'algorithme

La fonction `yin_yang` utilise une approche basée sur les stacks pour garantir que les parenthèses, crochets et accolades dans la chaîne sont correctement appariés et équilibrés.

#### `yin_yang`

La fonction `yin_yang` suit les étapes suivantes :

1. **Vérification du nombre de guillemets :** Si le nombre de guillemets simples ou doubles dans la chaîne `s` n'est pas pair, la fonction retourne `False`.

2. **Suppression des guillemets imbriqués :** La fonction `remove_nested_quotes` est appelée pour éliminer les guillemets imbriqués de la chaîne. Cette opération est linéaire, de l'ordre de O(n), où n est la longueur de la chaîne `s`.

3. **Vérification des parenthèses, crochets et accolades :** Une stack `stack` est utilisée pour suivre les caractères ouvrants et vérifier la correspondance avec les caractères fermants. La boucle parcourt chaque caractère de la chaîne, et si un caractère est une parenthèse, un crochet ou une accolade ouvrante, il est ajouté à la stack. Si le caractère est un caractère fermant, la fonction vérifie s'il correspond au caractère au sommet de la stack. Si la correspondance n'est pas respectée, la fonction retourne `False`.

4. **Renvoi du résultat :** Si la stack est vide à la fin de la boucle, la fonction retourne `True`, sinon, elle retourne `False`.

### Complexité algorithmique

La complexité totale de la fonction `yin_yang` est linéaire, de l'ordre de O(n), où n est la longueur de la chaîne `s`. Cela est dû à la boucle unique qui parcourt chaque caractère de la chaîne.

### Utilisation

La fonction `yin_yang` peut être utilisée comme suit dans un script Python :

```python
s = "(a + b) * [c - {d / e}]"
result = yin_yang(s)
print(result)
```

Dans cet exemple, la fonction yin_yang retournera True car les parenthèses, crochets et accolades sont correctement appariés.
