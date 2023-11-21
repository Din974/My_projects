/*
** EPITECH PROJECT, 2020
** binary
** File description:
** binary
*/

#include <stdlib.h>

int find_bigest_power_of_two(int nb, int *count)
{
    int pow = 1;

    while (nb > pow) {
        nb = nb - pow;
        pow = pow * 2;
        *count++;
    }
    return pow;
}

char *put_rest_of_zero(int pwr, char *res, int i)
{
    while (pwr > 0) {
        res[i] = '0';
        pwr = pwr / 2;
        i++;
    }
    return res;
}

int size_to_malloc(int nb)
{
    int pow = 1;
    int res = 0;

    while (nb > pow) {
        nb = nb - pow;
        pow = pow * 2;
        res++;
    }
    return res;
}

char *convert_binary(int nb)
{
    int bigest_pwr;
    int size = 0;
    char *res;
    int i = 0;

    bigest_pwr = find_bigest_power_of_two(nb, &size);
    res = malloc(sizeof(char) * size + 1);
    while (nb > 0) {
        if (nb - bigest_pwr >= 0) {
            nb = nb - bigest_pwr;
            res[i] = '1';
        }
        else
            res[i] = '0';
        bigest_pwr = bigest_pwr / 2;
        i++;
    }
    res = put_rest_of_zero(bigest_pwr, res, i);
    return res;
}