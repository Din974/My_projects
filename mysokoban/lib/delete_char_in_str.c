/*
** EPITECH PROJECT, 2020
** delete_char_in_str
** File description:
** delete_specific_char_in_a_str
*/

#include "my.h"

int count_delete(char *str, char delete)
{
    int i = 0;
    int count = 0;

    while (str[i] != '\0') {
        if (str[i] == delete && str[i + 1] == delete)
            count += 1;
        i++;
    }
    return count;
}

char *delete_char_in_str(char *str, char delete)
{
    int char_nbr = count_delete(str, delete);
    char *res = malloc(sizeof(char) * my_strlen(str) - char_nbr);
    int i = 0;
    int i2 = 0;

    while (str[i2] != '\0') {
        if (str[i2] == delete && str[i2 + 1] == delete) {
            while (str[i2 + 1] == delete)
                i2 += 1;
            str[i2] = ' ';
        }
        res[i] = str[i2];
        i++;
        i2 += 1;
    }
    return res;
}

int count_delete_double(char *str, char delete)
{
    int i = 0;
    int count = 0;

    while (str[i] != '\0') {
        if (str[i] == delete && str[i + 1] == delete)
            count += 1;
        i++;
    }
    return count;
}

char *delete_char_double_in_str(char *str, char delete)
{
    int char_nbr = count_delete(str, delete);
    char *res = malloc(sizeof(char) * my_strlen(str) - char_nbr);
    int i = 0;
    int i2 = 0;

    while (str[i2] != '\0') {
        if (str[i2] == delete && str[i2 + 1] == delete) {
            while (str[i2 + 1] == delete)
                i2 += 1;
        }
        res[i] = str[i2];
        i++;
        i2 += 1;
    }
    return res;
}