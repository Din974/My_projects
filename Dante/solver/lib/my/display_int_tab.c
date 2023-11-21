/*
** EPITECH PROJECT, 2020
** B-CPE-200-RUN-2-1-dante-luidgi.parinet
** File description:
** display_int_tab.c
*/

#include <stdlib.h>
#include <stdio.h>

void display_int_tab(int **tab, int x)
{
    for (int y = 0; tab[y] != NULL; y++) {
        for (int j = 0; j != x; j++)
            printf("%d", tab[y][j]);
        printf("\n");
    }
}