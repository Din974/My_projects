/*
** EPITECH PROJECT, 2029
** navy.h
** File description:
** navy.h
*/

#ifndef SOKOBAN_H_
#define SOKOBAN_H_

#include <unistd.h>
#include <curses.h>
#include <termios.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdio.h>

typedef struct position
{
    int x;
    int y;
    int state;
    char **map;
    int x_lim;
    int y_lim;
}pos_t;

void usage(void);
void sokoban(char *buffer);
char *delete_first_line(char *buffer);
pos_t key_management(pos_t pos, char **o_manage, int key);
int pos_y(char **map, char to_find);
int pos_x(char **map, char to_find, int number);
int str_contain_char(char *str, char to_find);
int how_many_char(char **map, char to_count);
char *remove_p(char *str);
void free_tab(char **tab);
void win(void);
int lose_cond(pos_t pos, char **o_man);
void lose(void);
void quit(void);
int count_taller_line(char **map);
int how_many_lines(char **map);

#endif