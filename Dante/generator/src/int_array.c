/*
** EPITECH PROJECT, 2020
** int_array
** File description:
** dante
*/

#include "generator.h"

int **alloc_int_array(int **res, int x, int y)
{
    int i = 0;

    res = malloc(sizeof(int *) * (y) + 1);
    while (i != y) {
        res[i] = malloc(sizeof(int) * (x));
        i++;
    }
    res[i] = NULL;
    return res;
}