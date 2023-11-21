/*
** EPITECH PROJECT, 2020
** B-CPE-200-RUN-2-1-dante-luidgi.parinet
** File description:
** solver.h
*/

#include <unistd.h>
#include <curses.h>
#include <termios.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>

typedef struct position
{
    int y;
    int x;
    int y_max;
    int x_max;
}pos_t;

typedef struct path_finding
{
    int y;
    int x;
    int is_visited;
    pos_t about;
    struct path_finding *next;
}path_t;

int **alloc_int_array(int **res, int x, int y);
void solver(char *buffer, int x, int y);
int all_path_visited(path_t *path);
int pos_and_list_match(pos_t pos, path_t *path);
void display_list(path_t *path);
int check_already_in_list(path_t *path, int y, int x);
void my_put_in_list(path_t **list, pos_t pos, pos_t about, int is_visited);
pos_t change_pos_t_value(pos_t pos, int which, int add);
int count_cells_around(pos_t pos, int **tab, path_t *path);
path_t *change_path_value_about_pos(pos_t pos, path_t *path);
int **find_path(int **tab, pos_t pos, path_t *path);
int check_for_loop(pos_t pos, path_t *path, int **tab);
pos_t if_pos_is_blocked(pos_t pos, path_t *path, int **tab);
int check_already_visited(path_t *path, int y, int x);
int check_for_add(path_t *path, int y, int x);
int check_for_count(path_t *path, int y, int x);
int check_value_is_visited(path_t *path, int y, int x);
path_t *set_a_node_start_of_list(path_t *path, int y, int x);
pos_t give_at_pos_path_value(path_t *path, pos_t pos);