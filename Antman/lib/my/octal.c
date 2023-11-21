/*
** EPITECH PROJECT, 2020
** octal
** File description:
** octal
*/

#include "my.h"
#include <stdlib.h>

char convert_triplet(char *triplet)
{
    int res = 0;
    int i = 0;
    int pwr = 1;

    while (triplet[i] != '\0') {
        if (triplet[i] == '1') {
            res = res + pwr;
        }
        pwr = pwr * 2;
        i++;
    }
    return (res + 48);
}

char *set_str_octal(char *str, int nb)
{
    char *res = malloc(sizeof(char) * my_strlen(convert_binary(nb)) + 4);
    int i = 0;
    int size = my_strlen(str);
    int a = 0;

    while ((size) > 3) {
        size = size - 3;
    }
    while (size < 3) {
        res[i] = '0';
        size++;
        i++;
    }
    while (str[a] != '\0') {
        res[i] = str[a];
        i++;
        a++;
    }
    return res;
}

char *convert_octal(int nb)
{
    int i = 0;
    int q = 0;
    int h = 0;
    char *res = malloc(sizeof(char) * my_strlen(convert_binary(nb)) + 3);
    char *triplet = malloc(sizeof(char) * 3 + 1);
    char *octal = malloc(sizeof(char) * my_strlen(convert_binary(nb)) / 3 + 3);

    res = convert_binary(nb);
    res = set_str_octal(res, nb);
    res = my_revstr(res);
    while (res[i] != '\0') {
        q = 0;
        while (q < 3 && res[i] != '\0') {
            triplet[q] = res[i];
            i++;
            q++;
        }
        octal[h] = convert_triplet(triplet);
        h++;
    }
    return (my_revstr(octal));
}