/*
** EPITECH PROJECT, 2021
** antman
** File description:
** antman
*/

#include "my.h"
#include "antman.h"

ppm_t check_first_nb(ppm_t ppm, char **tab)
{
    if (ppm.j == 0)
        ppm.cmp = my_strdup(tab[ppm.i]);
    else
        ppm.cmp = my_strdup(tab[ppm.i - 1]);
    return ppm;
}

void antman(char *file, char type)
{
    if (my_strlen(file) == 0)
        return;
    if (type == '1')
        compress_lyrics(conv_new_line(file));
    if (type == '2')
        compress_html(file);
    if (type == '3')
        compress_ppm(file);
}