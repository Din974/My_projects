/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#include <stdlib.h>

void my_putchar(char c);
int my_put_nbr(int nb);
int my_strlen(char *str);
char *my_revstr(char *str);
int my_putstr(char *str);
int my_getnbr(char *str);
char **my_str_to_word_array(char *str);
int x_pos(int **tab, char *buffer);
int y_pos(int **tab, char *buffer);
int **check_greater_square(char *buffer);

#endif
