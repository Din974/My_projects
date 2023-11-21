/*
** EPITECH PROJECT, 2020
** my_revstr
** File description:
** my_revstr
*/

char *my_revstr(char *str)
{
    int a = 0;
    int c = 0;
    int t = 0;

    while (str[a] != '\0')
        a = a + 1;
    a = a - 1;
    while (c < a) {
        t = str[a];
        str[a] = str[c];
        str[c] = t;
        c = c + 1;
        a = a - 1;
    }
    return str;
}