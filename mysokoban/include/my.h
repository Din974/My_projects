/*
** EPITECH PROJECT, 2029
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void my_putchar(char c);
void my_put_nbr(int num);
void my_putstr(char *str);
int my_strcmp(char *s1 , char *s2);
int strisnum(char const *str);
void my_printf(char *str, ...);
int my_getnbr(char *str);
void my_swap(int *a, int *b);
char *my_strcpy(char *dest, char const *src);
int my_strlen(char const *str);
char **my_str_to_word_array(char *str);
char *delete_char_in_str(char *str, char delete);
int my_strncmp(char const *s1, char const *s2, int n);
int my_char_isprintable(char c);
char *my_strcat(char *dest, char *src);
char *my_strcat_upgrade(char *dest, char *src);
char *my_strdup(char const *src);
void my_putchar_error(char c);
void my_putstr_error(char *str);
void my_putstr_error_exit(char *str);
void my_putstr_error_line(char *str);
int my_char_isalpha(char c);
int my_str_isalphanum(char const *str);
char *my_strconcat(char *dest, char *src);
int longer_line(char *str);

#define DEBUG_PRINTF(format, ...) \
    my_printf("\n%s:%d -> ["format"]\n", __FILE__, __LINE__, ##__VA_ARGS__)

#endif