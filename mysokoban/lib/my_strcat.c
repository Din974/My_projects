/*
** EPITECH PROJECT, 2020
** my_strcat
** File description:
** concate 2 stringd
*/

#include "my.h"

char *my_strcat(char *dest, char *src)
{
    int i = my_strlen(dest);
    int i2 = 0;

    while (src[i2] != '\0') {
        dest[i] = src[i2];
        i += 1;
        i2 += 1;
    }
    dest[i] = '\0';
    return dest;
}
