/*
** EPITECH PROJECT, 2020
** B-CPE-200-RUN-2-1-dante-luidgi.parinet
** File description:
** generator.c
*/

#include "generator.h"
#include "my.h"

int **create_link(cells_t *cell, int **tab)
{
    if (cell->y > cell->about.y) {
        tab[cell->about.y + 1][cell->x] = 2;
        tab[cell->y][cell->x] = 0;
    }
    if (cell->y < cell->about.y) {
        tab[cell->about.y - 1][cell->x] = 2;
        tab[cell->y][cell->x] = 0;
    }
    if (cell->x > cell->about.x) {
        tab[cell->y][cell->about.x + 1] = 2;
        tab[cell->y][cell->x] = 0;
    }
    if (cell->x < cell->about.x) {
        tab[cell->y][cell->about.x - 1] = 2;
        tab[cell->y][cell->x] = 0;
    }
    return tab;
}

int **change_random_cells(cells_t *cells, int **tab)
{
    int rand = rand_getpid(my_list_size(cells));
    int i = 0;

    for (; cells != NULL; cells = cells->next) {
        if (i == rand) {
            tab = create_link(cells, tab);
            return tab;
        }
        i++;
    }
    return tab;
}

int **prim_algo(int **tab, int x, int y)
{
    cells_t *cells = NULL;

    tab = fill_my_perfect_tab(tab, x, y);
    cells = search_available_cells(tab, y, x);
    while (cells != NULL) {
        tab = change_random_cells(cells, tab);
        cells = search_available_cells(tab, y, x);
    }
    return tab;
}

void perfect_generator(int x, int y)
{
    int **tab = alloc_int_array(tab, x, y);

    tab = prim_algo(tab, x, y);
    tab[0][0] = 0;
    tab[0][1] = 0;
    tab[y - 1][x - 1] = 0;
    (x % 2 == 1) ? tab[y - 1][x - 2] = 0 : 0;
    display_perfect_generator(tab, x, y);
}

void generator(int x, int y, int is_perfect)
{
    if (is_perfect == 1)
        perfect_generator(x, y);
    else
        imperfect_generator(x, y);
}