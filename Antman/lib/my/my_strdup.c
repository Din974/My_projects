/*
** EPITECH PROJECT, 2020
** my_strdup
** File description:
** my_strdup
*/

#include <stdlib.h>

char *my_strcpy(char *dest, char const *src);
int my_strlen(char const *str);

char *my_strdup(char const *src)
{
    int len = my_strlen(src);
    char *dest;

    if (src == NULL)
        return NULL;
    dest = malloc(sizeof(char) * len + 1);
    dest = my_strcpy(dest, src);
    return dest;
}