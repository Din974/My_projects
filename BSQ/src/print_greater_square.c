/*
** EPITECH PROJECT, 2020
** print_greater_square
** File description:
** bsq
*/

#include "my.h"
#include "bsq.h"

int x_pos(int **tab, char *buffer)
{
    int y = 0;
    int x = 0;
    int stock = 0;
    int pos_x = 0;
    int count = -1;
    int len = colums_len(buffer);

    while (y != lines_len(buffer)) {
        x = 0;
        count = -1;
        while (++count != len) {
            if (tab[y][x] > stock) {
                stock = tab[y][x];
                pos_x = x;
            }
            x++;
        }
        y++;
    }
    return pos_x;
}

int y_pos(int **tab, char *buffer)
{
    int y = 0;
    int x = 0;
    int stock = 0;
    int pos_y = 0;
    int count = -1;
    int len = colums_len(buffer);

    while (y != lines_len(buffer)) {
        x = 0;
        count = -1;
        while (++count != len) {
            if (tab[y][x] > stock) {
                stock = tab[y][x];
                pos_y = y;
            }
            x++;
        }
        y++;
    }
    return pos_y;
}

char **final_tab(int **tab, char *buffer)
{
    char **res = my_str_to_word_array(buffer);
    int x = x_pos(tab, buffer);
    int y = y_pos(tab, buffer);
    int limit = tab[y][x];
    int stop_y = y - limit;
    int pos_value = limit;

    while (y != stop_y) {
        x = x_pos(tab, buffer);
        limit = pos_value;
        while (limit != 0) {
            res[y][x] = 'x';
            x--;
            limit--;
        }
        y--;
    }
    return res;
}
