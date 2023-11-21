/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** my_printf
*/

#include "my_printf.h"
#include "my.h"

int len_res(int nb, int div)
{
    int count = 0;

    while (nb != 0) {
        nb = nb / div;
        count++;
    }
    return count;
}

void binary_base(int nb)
{
    int i = 0;
    char *res;

    if (nb == 0) {
        my_put_nbr(0);
        return;
    }
    res = malloc(sizeof(char) * len_res(nb, 2) + 1);
    while (nb != 0) {
        res[i] = (nb % 2) + 48;
        nb = nb / 2;
        i++;
    }
    res[i] = '\0';
    my_putstr(my_revstr(res));
    free(res);
}

void octale_base(int nb)
{
    int i = 0;
    char *res;

    if (nb == 0) {
        my_put_nbr(0);
        return;
    }
    res = malloc(sizeof(char) * len_res(nb, 8) + 1);
    while (nb != 0) {
        res[i] = (nb % 8) + 48;
        nb = nb / 8;
        i++;
    }
    res[i] = '\0';
    my_putstr(my_revstr(res));
    free(res);
}

void hexa_base_lowercase(int nb)
{
    int i = 0;
    char base[6] = "abcdef";
    char *res;

    if (nb == 0) {
        my_put_nbr(0);
        return;
    }
    res = malloc(sizeof(char) * len_res(nb, 16) + 1);
    while (nb != 0) {
        if (nb % 16 < 10)
            res[i] = (nb % 16) + 48;
        else
            res[i] = base[(nb % 16) - 10];
        nb = nb / 16;
        i++;
    }
    res[i] = '\0';
    my_putstr(my_revstr(res));
    free(res);
}

void hexa_base_uppercase(int nb)
{
    int i = 0;
    char base[6] = "ABCDEF";
    char *res;

    if (nb == 0) {
        my_put_nbr(0);
        return;
    }
    res = malloc(sizeof(char) * len_res(nb, 16) + 1);
    while (nb != 0) {
        if (nb % 16 < 10)
            res[i] = (nb % 16) + 48;
        else
            res[i] = base[(nb % 16) - 10];
        nb = nb / 16;
        i++;
    }
    res[i] = '\0';
    my_putstr(my_revstr(res));
    free(res);
}