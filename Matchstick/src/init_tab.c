/*
** EPITECH PROJECT, 2020
** B-CPE-200-RUN-2-1-matchstick-luidgi.parinet
** File description:
** init_tab.c
*/

#include "matchstick.h"
#include "my.h"

char **alloc_tab(char **tab, int tab_len)
{
    int i = 0;
    int line_len = tab_len * 2 + 1;

    tab = malloc(sizeof(char *) * tab_len - 1);
    while (i != tab_len) {
        tab[i] = malloc(sizeof(char) * line_len + 1);
        i++;
    }
    tab[i] = NULL;
    return tab;
}

void first_and_last_line(int tab_len)
{
    for (int i = 0; i != tab_len * 2 + 1; i++)
        my_printf("*");
    my_printf("\n");
}

char *fill_lines(char *line, int min, int max, int tab_len)
{
    line[0] = '*';
    for (int x = 1; x != min; x++)
        line[x] = ' ';
    for (int x = min; x != max + 1; x++)
        line[x] = '|';
    for (int x = max + 1; x != (tab_len * 2 + 1); x++)
        line[x] = ' ';
    line[tab_len * 2] = '*';
    line[tab_len * 2 + 1] = '\0';
    return line;
}

char **init_tab(int tab_len)
{
    char **tab = alloc_tab(tab, tab_len);
    int min = tab_len;
    int max = tab_len;

    for (int i = 0; i != tab_len; i++) {
        tab[i] = fill_lines(tab[i], min, max, tab_len);
        min--;
        max++;
    }
    return tab;
}

void print_tab(char **tab, int tab_len)
{
    first_and_last_line(tab_len);
    for (int i = 0; tab[i] != NULL; i++)
        my_printf("%s\n", tab[i]);
    first_and_last_line(tab_len);
}