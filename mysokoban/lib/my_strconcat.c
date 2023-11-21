/*
** EPITECH PROJECT, 2020
** my_strconcat
** File description:
** concate 2 string
*/

#include "my.h"

char *my_strconcat(char *dest, char *src)
{
    size_t size_dest = my_strlen(dest);
    size_t size_src = my_strlen(src);
    char *new = malloc(sizeof(char) * (size_dest + size_src + 1));

    my_strcpy(new, dest);
    my_strcpy(new + size_dest, src);
    return (new);
}