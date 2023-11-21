/*
** EPITECH PROJECT, 2020
** B-CPE-200-RUN-2-1-dante-luidgi.parinet
** File description:
** change_pos_value.c
*/

#include "solver.h"
#include "my.h"

pos_t change_pos_t_value(pos_t pos, int which, int add)
{
    if (add == -1 && which == 0)
        pos.y -= 1;
    if (add == -1 && which == 1)
        pos.x -= 1;
    if (add == 1 && which == 0)
        pos.y += 1;
    if (add == 1 && which == 1)
        pos.x += 1;
    return pos;
}

pos_t if_pos_is_blocked(pos_t pos, path_t *path, int **tab)
{
    path_t *tmp = path;

    for (; path != NULL; path = path->next) {
        if (path->is_visited == 0) {
            pos.y = path->y;
            pos.x = path->x;
            return pos;
        }
    }
    printf("no solution found");
    exit(0);
}

path_t *change_path_value_about_pos(pos_t pos, path_t *path)
{
    path_t *tmp = NULL;
    pos_t pos_cell;

    for (; path != NULL; path = path->next) {
        pos_cell.y = path->y;
        pos_cell.x = path->x;
        if (path->y == pos.y && path->x == pos.x)
            my_put_in_list(&tmp, pos_cell, path->about, 1);
        else
            my_put_in_list(&tmp, pos_cell, path->about, path->is_visited);
    }
    my_rev_list(&tmp);
    return tmp;
}

pos_t give_at_pos_path_value(path_t *path, pos_t pos)
{
    pos.x = path->x;
    pos.y = path->y;
    return pos;
}