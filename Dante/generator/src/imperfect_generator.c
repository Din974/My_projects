/*
** EPITECH PROJECT, 2020
** B-CPE-200-RUN-2-1-dante-luidgi.parinet
** File description:
** imperfect_generator.c
*/

#include "generator.h"

void imperfect_generator(int x_max, int y_max)
{
    int **tab = alloc_int_array(tab, x_max, y_max);

    if ((y_max == 1) || (x_max == 1) || (x_max == 2)) {
        print_stars_errors(x_max, y_max);
        print_is_two(x_max, y_max);
        return;
    }
    tab = prim_algo(tab, x_max, y_max);
    tab[0][0] = 0;
    tab[0][1] = 0;
    tab[y_max - 1][x_max - 1] = 0;
    for (int y = 1; y != y_max; y++) {
        for (int x = 1; x != x_max; x++) {
            if (x < x_max - 1 && tab[y][x] == 1 && tab[y][x - 1] == 1 &&
                tab[y][x + 1] == 1)
                tab[y][x] = 0;
        }
    }
    (x_max % 2 == 1) ? tab[y_max - 1][x_max - 2] = 0 : 0;
    display_perfect_generator(tab, x_max, y_max);
}