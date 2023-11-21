/*
** EPITECH PROJECT, 2020
** B-CPE-200-RUN-2-1-dante-luidgi.parinet
** File description:
** path.c
*/

#include "solver.h"

int check_for_count(path_t *path, int y, int x)
{
    for (path_t *tmp = path; tmp != NULL; tmp = tmp->next) {
        if (tmp->y == y && tmp->x == x && tmp->is_visited == 1)
            return 0;
    }
    return 1;
}

int **find_path(int **tab, pos_t pos, path_t *path)
{
    for (; pos.y != 0 && pos.x != 0;) {
        for (path_t *tmp = path; tmp != NULL; tmp = tmp->next) {
            if (tmp->y == pos.y && tmp->x == pos.x) {
                pos.y = tmp->about.y;
                pos.x = tmp->about.x;
                tab[pos.y][pos.x] = 2;
            }
        }
    }
    return tab;
}