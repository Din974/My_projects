/*
** EPITECH PROJECT, 2021
** key_management
** File description:
** sokoban
*/

#include "my.h"
#include "sokoban.h"

pos_t down_key_arrow(pos_t pos, char **o_man)
{
    char o = o_man[pos.y + 1][pos.x];

    if (pos.map[pos.y + 1][pos.x] != 'X') {
        pos.map[pos.y + 1][pos.x] = 'P';
        pos.map[pos.y][pos.x] = (pos.state == 1) ? 'O' : ' ';
        pos.state = (o == 'O') ? 1 : 0;
        pos.y += 1;
    }else if (pos.map[pos.y + 1][pos.x] == 'X' &&
        pos.map[pos.y + 2][pos.x] != '#' &&
        pos.map[pos.y + 2][pos.x] != 'X') {
        pos.map[pos.y + 2][pos.x] = 'X';
        pos.map[pos.y + 1][pos.x] = 'P';
        pos.map[pos.y][pos.x] = (pos.state == 1) ? 'O' : ' ';
        pos.state = (o == 'O') ? 1 : 0;
        pos.y += 1;
    }
    (pos.map[pos.y + 1][pos.x] == 'X' && pos.map[pos.y + 2][pos.x] == 'X' &&
    o_man[pos.y][pos.x] == 'O') ? pos.state = 1 : 0;
    return pos;
}

pos_t up_key_arrow(pos_t pos, char **o_man)
{
    char o = o_man[pos.y - 1][pos.x];

    if (pos.map[pos.y - 1][pos.x] != 'X' && pos.y >= 0) {
        pos.map[pos.y - 1][pos.x] = 'P';
        pos.map[pos.y][pos.x] = (pos.state == 1) ? 'O' : ' ';
        pos.state = (o == 'O') ? 1 : 0;
        pos.y -= 1;
    }else if (pos.map[pos.y - 1][pos.x] == 'X' &&
        pos.map[pos.y - 2][pos.x] != '#' &&
        pos.map[pos.y - 2][pos.x] != 'X') {
        pos.map[pos.y - 2][pos.x] = 'X';
        pos.map[pos.y - 1][pos.x] = 'P';
        pos.map[pos.y][pos.x] = (pos.state == 1) ? 'O' : ' ';
        pos.state = (o == 'O') ? 1 : 0;
        pos.y -= 1;
    }
    (pos.map[pos.y - 1][pos.x] == 'X' && pos.map[pos.y - 2][pos.x] == 'X' &&
    o_man[pos.y][pos.x] == 'O') ? pos.state = 1 : 0;
    return pos;
}

pos_t left_key_arrow(pos_t pos, char **o_man)
{
    char o = o_man[pos.y][pos.x - 1];

    if (pos.map[pos.y][pos.x - 1] != 'X' && pos.x - 1 >= 0) {
        pos.map[pos.y][pos.x - 1] = 'P';
        pos.map[pos.y][pos.x] = (pos.state == 1) ? 'O' : ' ';
        pos.state = (o == 'O') ? 1 : 0;
        pos.x -= 1;
    }else if (pos.map[pos.y][pos.x - 1] == 'X' &&
        pos.map[pos.y][pos.x - 2] != '#' &&
        pos.map[pos.y][pos.x - 2] != 'X' && pos.x - 2 >= 0) {
        pos.map[pos.y][pos.x - 2] = 'X';
        pos.map[pos.y][pos.x - 1] = 'P';
        pos.map[pos.y][pos.x] = (pos.state == 1) ? 'O' : ' ';
        pos.state = (o == 'O') ? 1 : 0;
        pos.x -= 1;
    }
    (pos.map[pos.y][pos.x - 2] == 'X' && pos.map[pos.y][pos.x - 1] == 'X' &&
    o_man[pos.y][pos.x] == 'O') ? pos.state = 1 : 0;
    return pos;
}

pos_t right_key_arrow(pos_t pos, char **o_man)
{
    char o = o_man[pos.y][pos.x + 1];

    if (pos.map[pos.y][pos.x + 1] != 'X' && pos.x + 1 <= pos.x_lim) {
        pos.map[pos.y][pos.x + 1] = 'P';
        pos.map[pos.y][pos.x] = (pos.state == 1) ? 'O' : ' ';
        pos.state = (o == 'O') ? 1 : 0;
        pos.x += 1;
    }else if (pos.map[pos.y][pos.x + 1] == 'X' &&
        pos.map[pos.y][pos.x + 2] != '#' &&
        pos.map[pos.y][pos.x + 2] != 'X' && pos.x + 2 <= pos.x_lim) {
        pos.map[pos.y][pos.x + 2] = 'X';
        pos.map[pos.y][pos.x + 1] = 'P';
        pos.map[pos.y][pos.x] = (pos.state == 1) ? 'O' : ' ';
        pos.state = (o == 'O') ? 1 : 0;
        pos.x += 1;
    }
    (pos.map[pos.y][pos.x + 2] == 'X' && pos.map[pos.y][pos.x + 1] == 'X' &&
    o_man[pos.y][pos.x] == 'O') ? pos.state = 1 : 0;
    return pos;
}

pos_t key_management(pos_t pos, char **o_manage, int key)
{
    pos = (key == KEY_DOWN && pos.map[pos.y + 1][pos.x] != '#') ?
    down_key_arrow(pos, o_manage) :
    (key == KEY_UP && pos.map[pos.y - 1][pos.x] != '#') ?
    up_key_arrow(pos, o_manage) :
    (key == KEY_RIGHT && pos.map[pos.y][pos.x + 1] != '#') ?
    right_key_arrow(pos, o_manage) :
    (key == KEY_LEFT && pos.map[pos.y][pos.x - 1] != '#') ?
    left_key_arrow(pos, o_manage) : pos;
    return pos;
}