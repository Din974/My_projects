/*
** EPITECH PROJECT, 2020
** my_strcmp
** File description:
** compare a str to another str
*/

#include "my.h"

int s1_same_len_s2(char *s1, char *s2)
{
    if (my_strlen(s1) > my_strlen(s2))
        return 1;
    if (my_strlen(s1) < my_strlen(s2))
        return -1;
    return 0;
}

int my_strcmp(char *s1, char *s2)
{
    int i = 0;

    if (s1_same_len_s2(s1, s2) != 0)
        return 1;
    while (s1[i] && s2[i]) {
        if (s1[i] > s2[i])
            return 1;
        else if (s1[i] < s2[i])
            return -1;
        i++;
    }
    return 0;
}