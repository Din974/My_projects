/*
** EPITECH PROJECT, 2020
** my_putchar.c
** File description:
** putchar
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putchar_int(int c)
{
    write(1, &c, 1);
}
