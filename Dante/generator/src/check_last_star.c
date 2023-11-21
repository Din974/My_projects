/*
** EPITECH PROJECT, 2020
** B-CPE-200-RUN-2-1-dante-luidgi.parinet
** File description:
** check_last_zero.c
*/

#include "generator.h"

int last_star_y(int **tab, int x_max)
{
    int y = 0;
    int stock = 0;

    for (; tab[y] != NULL; y++)
        for (int x = 0; x != x_max; x++)
            if (tab[y][x] == 0 || tab[y][x] == 2)
                stock = y;
    return stock;
}

int last_star_x(int **tab, int x_max)
{
    int stock = 0;
    int y = last_star_y(tab, x_max);

    for (int x = 0; x != x_max; x++)
        if (tab[y][x] == 0 || tab[y][x] == 2)
            stock = x;
    return stock;
}