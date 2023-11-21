/*
** EPITECH PROJECT, 2020
** B-CPE-200-RUN-2-1-dante-luidgi.parinet
** File description:
** perfect_generator.c
*/

#include "generator.h"
#include "my.h"

int **fill_my_perfect_tab(int **tab, int x, int y)
{
    for (int i = 0; tab[i] != NULL; i++)
        for (int j = 0; j != x; j++)
            tab[i][j] = 1;
    tab[1][1] = 0;
    return tab;
}

void display_perfect_generator(int **tab, int x, int y)
{
    for (int i = 0; i != y; i++) {
        for (int j = 0; j != x; j++) {
            if (tab[i][j] == 1)
                printf("X");
            else
                printf("*");
        }
        if (i != y - 1)
            printf("\n");
    }
}