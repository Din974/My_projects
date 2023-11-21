/*
** EPITECH PROJECT, 2020
** B-CPE-200-RUN-2-1-dante-luidgi.parinet
** File description:
** search_availables_cells.c
*/

#include "generator.h"
#include "my.h"

int count_cells_available(int **tab, int y_max, int x_max, pos_t pos)
{
    int count = 0;

    if (pos.y - 2 >= 1 && tab[pos.y - 2][pos.x] != 0)
        count += 1;
    if (pos.y + 2 < y_max && tab[pos.y + 2][pos.x] != 0)
        count += 1;
    if (pos.x - 2 >= 1 && tab[pos.y][pos.x - 2] != 0)
        count += 1;
    if (pos.x + 2 < x_max && tab[pos.y][pos.x + 2] != 0)
        count += 1;
    return count;
}

void add_cells_around(cells_t **cells, int **tab, pos_t pos)
{
    if (pos.y - 2 >= 1 && tab[pos.y - 2][pos.x] != 0)
        my_put_in_list(cells, pos.y - 2, pos.x, pos);
    if (pos.y + 2 < pos.y_max && tab[pos.y + 2][pos.x] != 0)
        my_put_in_list(cells, pos.y + 2, pos.x, pos);
    if (pos.x - 2 >= 1 && tab[pos.y][pos.x - 2] != 0)
        my_put_in_list(cells, pos.y, pos.x - 2, pos);
    if (pos.x + 2 < pos.x_max && tab[pos.y][pos.x + 2] != 0)
        my_put_in_list(cells, pos.y, pos.x + 2, pos);
}

cells_t *search_available_cells(int **tab, int y_max, int x_max)
{
    cells_t *cells = NULL;
    pos_t pos;

    pos.y_max = y_max;
    pos.x_max = x_max;
    for (int y = 0; y != y_max; y++) {
        pos.y = y;
        for (int x = 0; x != x_max; x++) {
            pos.x = x;
            if (tab[y][x] == 0 && count_cells_available(tab, y_max, x_max, pos)
                != 0)
                add_cells_around(&cells, tab, pos);
        }
    }
    return cells;
}