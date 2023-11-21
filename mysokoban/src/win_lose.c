/*
** EPITECH PROJECT, 2021
** win_lose
** File description:
** sokoban
*/

#include "my.h"
#include "sokoban.h"

int how_many_char_lose(char **map, char **o_man, char to_count)
{
    int count = 0;
    int x = 0;

    for (int y = 0; map[y] != NULL; y++) {
        x = 0;
        if (str_contain_char(map[y], to_count) == 0) {
            while (map[y][x] != '\0') {
                count += (map[y][x] == to_count && o_man[y][x] != 'O') ? 1 : 0;
                x++;
            }
        }
    }
    return count;
}

int x_pos_is_valid(pos_t pos, int y, int x)
{
    if (((pos.map[y - 1][x] == '#' || pos.map[y - 1][x] == 'X') &&
        (pos.map[y][x - 1] == '#' || pos.map[y][x - 1] == 'X')) ||
        ((pos.map[y - 1][x] == '#' || pos.map[y - 1][x] == 'X') &&
        (pos.map[y][x + 1] == '#' || pos.map[y][x + 1] == 'X')) ||
        ((pos.map[y + 1][x] == '#' || pos.map[y + 1][x] == 'X') &&
        (pos.map[y][x - 1] == '#' || pos.map[y][x - 1] == 'X')) ||
        ((pos.map[y + 1][x] == '#' || pos.map[y + 1][x] == 'X') &&
        (pos.map[y][x + 1] == '#' || pos.map[y][x + 1] == 'X')))
        return 1;
    return 0;
}

int check_lose(pos_t pos, char **o_man)
{
    int count = how_many_char_lose(pos.map, o_man, 'X');

    for (int y = 0; pos.map[y] != NULL; y++) {
        for (int x = 0; pos.map[y][x] != '\0'; x++) {
            if (pos.map[y][x] == 'X') {
                if (x_pos_is_valid(pos, y, x) == 1 &&
                    o_man[y][x] != 'O')
                    count--;
            }
        }
    }
    if (count == 0)
        return 1;
    return 0;
}

int lose_cond(pos_t pos, char **o_man)
{
    if (pos.map[pos.y + 1][pos.x] == '#' && pos.map[pos.y - 1][pos.x] == '#' &&
        pos.map[pos.y][pos.x + 1] == '#' && pos.map[pos.y][pos.x - 1] == '#')
        return 1;
    if (check_lose(pos, o_man) == 1)
        return 1;
    return 0;
}