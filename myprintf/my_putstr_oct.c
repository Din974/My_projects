/*
** EPITECH PROJECT, 2020
** my_putstr_oct
** File description:
** my_putstr_oct
*/

#include "my_printf.h"
#include "my.h"

void my_putchar(char c);

void octale_base_ascii(int nb)
{
    int i = 0;
    char *res = malloc(sizeof(char) * 4);

    while (i != 3) {
        res[i] = (nb % 8) + 48;
        nb = nb / 8;
        i++;
    }
    res[i] = '\0';
    my_putstr(my_revstr(res));
    free(res);
}

void my_putstr_oct(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < 32 || str[i] >= 127) {
            my_putchar('\\');
            octale_base_ascii(str[i]);
            i++;
        }
        my_putchar(str[i]);
        i++;
    }
}