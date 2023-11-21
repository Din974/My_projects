/*
** EPITECH PROJECT, 2021
** sokoban
** File description:
** sokoban
*/

#include "my.h"
#include "sokoban.h"

pos_t init_pos(pos_t pos, char **map)
{
    pos.y = pos_y(map, 'P');
    pos.x = pos_x(map, 'P', 1);
    pos.map = map;
    pos.x_lim = count_taller_line(pos.map);
    pos.y_lim = how_many_lines(pos.map);
    return pos;
}

void init_ncurse(void)
{
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
}

void sokoban(char *buffer)
{
    char **map = my_str_to_word_array(buffer);
    pos_t pos = init_pos(pos, map);
    char **o_management = my_str_to_word_array(remove_p(buffer));
    int key = 0;

    init_ncurse();
    while (key != ' ') {
        (key == 'q') ? quit() : 0;
        (how_many_char(pos.map, 'O') == 0 && pos.state == 0) ? win() :
        (lose_cond(pos, o_management) == 1) ? lose() : 0;
        clear();
        refresh();
        for (int i = 0; pos.map[i] != NULL; i++)
            printw("%s\n", pos.map[i]);
        key = getch();
        pos = key_management(pos, o_management, key);
    }
    endwin();
    free_tab(map);
    return sokoban(buffer);
}