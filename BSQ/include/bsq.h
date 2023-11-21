/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** my.h
*/

#ifndef BSQ_H_
#define BSQ_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int buffer_size(char *pathname, int fd);
char *read_buffer(char *pathname, int fd, int size);
int colums_len(char *buffer);
char *search_square(char *buffer);
int lines_len(char *buffer);
int check_line_quality(char *buffer);
char **final_tab(int **tab, char *buffer);
int check_obstacle_alone(char *buffer);
int check_empty(char *buffer);
void fill_x_empty(char *buffer);
void print_special(char *buffer);
void print_res(char **res);

#endif