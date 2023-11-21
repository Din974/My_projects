/*
** EPITECH PROJECT, 2021
** my_str_to_tab
** File description:
** my_str_to_tab
*/

#include "my.h"

char *cpy_word(char *dest, char const *str, int *i, char c)
{
    int length = 0;

    while (str[*i]) {
        if (str[*i] == c) {
            (*i)++;
            dest[length] = '\0';
            return (dest);
        }
        dest[length] = str[*i];
        length++;
        (*i)++;
    }
    dest[length] = '\0';
    return dest;
}

int get_word(char const *str, char c)
{
    int i = 0;
    int word = 0;

    while (str[i]) {
        if (i == 0 && str[i] != c)
            word++;
        if (str[i - 1] == c) {
            if (str[i] != c)
                word++;
        }
        i++;
    }
    return word;
}

int my_malloc(char const *str, int *i, char c)
{
    int  length = 0;

    if (str == NULL)
        return 0;
    while (str[*i]) {
        if (str[*i] == c) {
            (*i)++;
            return (length);
        }
        (*i)++;
        length++;
    }
    return (length);
}

char **my_str_to_tab(char const *str, char c)
{
    int word = get_word(str, c);
    int j = 0;
    int i = 0;
    int k = 0;
    char **tab = malloc(sizeof(char *) * (word + 1));

    while (j < word) {
        tab[j] = malloc(sizeof(char) * (my_malloc(str, &i, c) + 1));
        tab[j] = cpy_word(tab[j], str, &k, c);
        j++;
    }
    tab[j] = '\0';
    return (tab);
}