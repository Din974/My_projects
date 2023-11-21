/*
** EPITECH PROJECT, 2020
** B-CPE-200-RUN-2-1-dante-luidgi.parinet
** File description:
** count_cells_around.c
*/

#include "solver.h"

int count_cells_around(pos_t pos, int **tab, path_t *path)
{
    int count = 0;

    if (pos.x + 1 < pos.x_max && tab[pos.y][pos.x + 1] == 0 &&
        check_for_count(path, pos.y, pos.x + 1) == 1)
        count += 1;
    if (pos.x - 1 >= 0 && tab[pos.y][pos.x - 1] == 0 &&
        check_for_count(path, pos.y, pos.x - 1) == 1)
        count += 1;
    if (pos.y + 1 < pos.y_max && tab[pos.y + 1][pos.x] == 0 &&
        check_for_count(path, pos.y + 1, pos.x) == 1)
        count += 1;
    if (pos.y - 1 >= 0 && tab[pos.y - 1][pos.x] == 0 &&
        check_for_count(path, pos.y - 1, pos.x) == 1)
        count += 1;
    return count;
}