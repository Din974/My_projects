/*
** EPITECH PROJECT, 2020
** putstr_error
** File description:
** display a string on error ouput
*/

#include "my.h"

void my_putchar_error(char c)
{
    write(2, &c, 1);
}

void my_putstr_error(char *str)
{
    pid_t pid;
    int status;

    for (int i = 0; str[i] != '\0'; i++)
        my_putchar_error(str[i]);
}

void my_putstr_error_exit(char *str)
{
    pid_t pid;
    int status;

    for (int i = 0; str[i] != '\0'; i++)
        my_putchar_error(str[i]);
    exit(1);
}