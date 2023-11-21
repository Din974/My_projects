/*
** EPITECH PROJECT, 2020
** int_array
** File description:
** dante
*/

#include "solver.h"

int **alloc_int_array(int **res, int x, int y)
{
    int i = 0;

    res = malloc(sizeof(int *) * (y));
    while (i != y) {
        res[i] = malloc(sizeof(int) * (x));
        i++;
    }
    return res;
}