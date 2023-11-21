/*
** EPITECH PROJECT, 2021
** antman
** File description:
** antman
*/

#include "my.h"
#include "antman.h"

dppm_t get_single_nb(dppm_t dppm, char *file)
{
    while (file[dppm.i] != '\n') {
        my_putchar(file[dppm.i]);
        dppm.i++;
    }
    return dppm;
}

void giantman(char *file, char type)
{
    if (my_strlen(file) == 0)
        return;
    if (type == '1')
        decompress_lyrics(file);
    if (type == '2')
        decompress_html(file);
    if (type == '3')
        decompress_ppm(file);
}