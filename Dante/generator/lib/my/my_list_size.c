/*
** EPITECH PROJECT, 2020
** B-CPE-200-RUN-2-1-dante-luidgi.parinet
** File description:
** my_list_size.c
*/

#include "../../include/generator.h"

int my_list_size(cells_t *cells)
{
    int i = 0;

    for (; cells != NULL; cells = cells->next)
        i++;
    return i;
}