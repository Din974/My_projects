/*
** EPITECH PROJECT, 2021
** useful_files
** File description:
** sokoban
*/

#include "my.h"
#include "sokoban.h"

int how_many_char(char **map, char to_count)
{
    int count = 0;
    int x = 0;

    for (int y = 0; map[y] != NULL; y++) {
        x = 0;
        if (str_contain_char(map[y], to_count) == 0) {
            while (map[y][x] != '\0') {
                count += (map[y][x] == to_count) ? 1 : 0;
                x++;
            }
        }
    }
    return count;
}

int str_contain_char(char *str, char to_find)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == to_find)
            return 0;
    }
    return 1;
}

int pos_y(char **map, char to_find)
{
    for (int i = 0; map[i] != NULL; i++) {
        if (str_contain_char(map[i], to_find) == 0)
            return i;
    }
}

int pos_x(char **map, char to_find, int number)
{
    int y = pos_y(map, to_find);
    int x = 0;
    int i = 0;

    while (i != number) {
        i += (map[y][x] == to_find && i != number) ? 1 : 0;
        x++;
    }
    return x - 1;
}

int pos_x_by_str(char *str, char to_find, int number)
{
    int x = 0;
    int i = 0;

    while (i != number) {
        i += (str[x] == to_find && i != number) ? 1 : 0;
        x++;
    }
    return x - 1;
}