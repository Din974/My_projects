/*
** EPITECH PROJECT, 2020
** B-CPE-200-RUN-2-1-dante-luidgi.parinet
** File description:
** solver.c
*/

#include "solver.h"
#include "my.h"

int **fill_for_solve(int **tab, char *buffer)
{
    int y = 0;
    int x = 0;

    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n') {
            y += 1;
            x = 0;
        }
        if (buffer[i] == 'X')
            tab[y][x] = 1;
        if (buffer[i] == '*')
            tab[y][x] = 0;
        if (buffer[i] != '\n')
            x++;
    }
    return tab;
}

void add_all_neighbors_unvisited(pos_t pos, path_t **path, int **tab,
pos_t about)
{
    about = pos;
    if (pos.x + 1 < pos.x_max && tab[pos.y][pos.x + 1] == 0 &&
        check_for_count(*path, pos.y, pos.x + 1) == 1) {
        my_put_in_list(path, change_pos_t_value(pos, 1, 1), about, 0);
    }
    if (pos.x - 1 >= 0 && tab[pos.y][pos.x - 1] == 0 &&
        check_for_count(*path, pos.y, pos.x - 1) == 1) {
        my_put_in_list(path, change_pos_t_value(pos, 1, -1), about, 0);
    }
    if (pos.y + 1 <= pos.y_max - 1 && tab[pos.y + 1][pos.x] == 0 &&
        check_for_count(*path, pos.y + 1, pos.x) == 1) {
        my_put_in_list(path, change_pos_t_value(pos, 0, 1), about, 0);
    }
    if (pos.y - 1 >= 0 && tab[pos.y - 1][pos.x] == 0 &&
        check_for_count(*path, pos.y - 1, pos.x) == 1) {
        my_put_in_list(path, change_pos_t_value(pos, 0, -1), about, 0);
    }
}

int **bfs_algo(path_t *path, pos_t pos, pos_t about, int **tab)
{
    int check = 0;

    my_put_in_list(&path, pos, about, 1);
    while (1) {
        check = count_cells_around(pos, tab, path);
        if (pos.y == pos.y_max - 1 && pos.x == pos.x_max - 1)
            break;
        if (check != 0) {
            pos = give_at_pos_path_value(path, pos);
            path->is_visited = 1;
            add_all_neighbors_unvisited(pos, &path, tab, about);
        }else {
            path = change_path_value_about_pos(pos, path);
            pos = if_pos_is_blocked(pos, path, tab);
            add_all_neighbors_unvisited(pos, &path, tab, about);
        }
    }
    tab = find_path(tab, pos, path);
    tab[pos.y_max - 1][pos.x_max - 1] = 2;
    return tab;
}

void display_solver(int **tab, int x, int y)
{
    for (int i = 0; i != y; i++) {
        for (int j = 0; j != x; j++) {
            if (tab[i][j] == 0)
                printf("*");
            if (tab[i][j] == 1)
                printf("X");
            if (tab[i][j] == 2)
                printf("o");
        }
        if (i != y - 1)
            printf("\n");
    }
}

void solver(char *buffer, int x, int y)
{
    int **tab = NULL;
    path_t *path = NULL;
    pos_t pos = {0, 0, y, x};
    pos_t about = {0, 0, y, x};

    if (y == 1) {
        for (int i = 0; buffer[i] != '\0'; i++)
            printf("o");
        return;
    }
    if (x == 1) {
        for (int i = 0; buffer[i] != '\0'; i++)
            (buffer[i] != '\n') ? printf("o") : printf("\n");
        return;
    }
    tab = alloc_int_array(tab, x, y);
    tab = fill_for_solve(tab, buffer);
    tab = bfs_algo(path, pos, about, tab);
    display_solver(tab, x, y);
}