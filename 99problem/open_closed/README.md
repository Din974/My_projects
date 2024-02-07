# Projet Open Closed

## Introduction

Ce projet implémente une fonction `open_closed` qui vérifie l'équilibre des parenthèses, crochets et accolades dans une chaîne de caractères. La fonction retourne `True` si la chaîne est équilibrée, sinon `False`.

### Fonctionnement des Fonctions

#### `check_pairs`

Cette fonction parcourt la chaîne de caractères et vérifie si chaque parenthèse ouvrante a une correspondance avec une parenthèse fermante ultérieure. Elle retourne `True` si une paire est trouvée, sinon `False`.

#### `delete_pairs`

Cette fonction modifie la chaîne de caractères en supprimant la première paire de parenthèses, crochets ou accolades qu'elle trouve. Elle est utilisée pour éliminer les paires dans la chaîne jusqu'à ce qu'il n'en reste plus.

#### `last_check`

Cette fonction vérifie si la chaîne de caractères finale ne contient plus de parenthèses, crochets ou accolades. Si elle trouve un caractère ouvrant ou fermant, elle retourne `False`, sinon `True`.

#### `open_closed`

La fonction principale `open_closed` vérifie d'abord si le nombre de guillemets simples et doubles est pair. Ensuite, elle entre dans une boucle qui, tant qu'il y a des paires de parenthèses, crochets ou accolades dans la chaîne, utilise la fonction `delete_pairs` pour les supprimer. Après la boucle, la fonction effectue une dernière vérification avec `last_check`. Si toutes les conditions sont remplies, la fonction retourne `True`, sinon `False`.

##### Complexité algorithmique

La complexité de la fonction `open_closed` dépend principalement de la longueur de la chaîne d'entrée. La boucle principale peut potentiellement parcourir chaque caractère de la chaîne, ce qui donne une complexité de l'ordre de O(n^2), où n est la longueur de la chaîne.

###### Utilisation

La fonction `open_closed` peut être utilisée comme suit dans un script Python :

```python
s = "{[()]}"
result = open_closed(s)
print(result)
```

Dans cet exemple, la chaîne "{[()]}" est équilibrée et la fonction retournera True.
