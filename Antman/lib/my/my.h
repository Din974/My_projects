/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** my.h
*/

#ifndef __DEF_MY__
#define __DEF_MY__

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char *my_strdup(char const *src);
int my_getnbr(char *str);
int my_put_nbr(int n);
void my_putchar(char c);
int my_putstr(char const *str);
char *my_revstr(char *str);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
void *my_calloc(int mem, int size);
char *my_strcpy(char *dest, char *src);
int my_strlen(char const *str);
char *convert_octal(int nb);
char *convert_binary(int nb);
char **my_str_to_word_array(char const *str);
char **my_str_to_tab(char const *str, char c);

#endif
