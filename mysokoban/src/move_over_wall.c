/*
** EPITECH PROJECT, 2021
** move_over_wall
** File description:
** sokoban
*/

#include "my.h"
#include "sokoban.h"

int count_taller_line(char **map)
{
    int stock = 0;

    for (int y = 0; map[y] != NULL; y++) {
        if (my_strlen(map[y]) > stock)
            stock = my_strlen(map[y]);
    }
    return stock - 1;
}

int how_many_lines(char **map)
{
    int y = 0;

    for (; map[y] != NULL; y++);
    return y - 1;
}