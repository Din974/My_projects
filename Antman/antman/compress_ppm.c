/*
** EPITECH PROJECT, 2021
** compress_ppm
** File description:
** compress_ppm
*/

#include "my.h"
#include "antman.h"

int go_to_rgb_nb(char *file)
{
    int i = 0;
    int count = 0;

    while (file[i] != '\0') {
        if (file[i] == '\n')
            count++;
        i++;
        if (count == 3)
            break;
    }
    if (file[i] == '#') {
        while (file[i] != '\n')
            i++;
        i++;
    }
    return i;
}

void print_occur(ppm_t ppm)
{
    my_putchar('\n');
    my_put_nbr(ppm.count);
    my_putchar('|');
    my_putstr(ppm.cmp);
}

ppm_t init_struct(ppm_t ppm, int i)
{
    ppm.i = i;
    ppm.j = 0;
    ppm.count = 0;
    return ppm;
}

ppm_t check_repetition(ppm_t ppm, char **tab)
{
    ppm = check_first_nb(ppm, tab);
    ppm.count = 1;
    if (my_strcmp(ppm.cmp, tab[ppm.i]) != 0) {
        my_putchar('\n');
        my_putstr(ppm.cmp);
        ppm.i++;
        ppm.cmp = my_strdup(tab[ppm.i]);
    }
    else {
        while (my_strcmp(ppm.cmp, tab[ppm.i]) == 0) {
            ppm.count++;
            ppm.i++;
        }
        if (ppm.j == 0)
            ppm.count--;
        print_occur(ppm);
        ppm.j++;
        ppm.i++;
    }
    return ppm;
}

void compress_ppm(char *file)
{
    ppm_t ppm = init_struct(ppm, go_to_rgb_nb(file));
    char **tab = NULL;

    while (ppm.count != ppm.i - 1) {
        my_putchar(file[ppm.count]);
        ppm.count++;
    }
    tab = my_str_to_tab(&file[ppm.i], '\n');
    ppm.i = 0;
    while (tab[ppm.i] != NULL)
        ppm = check_repetition(ppm, tab);
    my_putchar('\n');
}