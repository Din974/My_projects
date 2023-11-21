/*
** EPITECH PROJECT, 2021
** useful_files
** File description:
** sokoban
*/

#include "my.h"
#include "sokoban.h"

char *remove_p(char *str)
{
    char *new = malloc(sizeof(char) * my_strlen(str) + 1);
    int i = 0;

    while (str[i] != '\0') {
        new[i] = (str[i] == 'P') ? ' ' : str[i];
        i++;
    }
    new[i] = '\0';
    return str;
}

void free_tab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++)
        free(tab[i]);
    free(tab);
}

void win(void)
{
    endwin();
    exit(0);
}

void lose(void)
{
    endwin();
    exit(1);
}

void quit(void)
{
    endwin();
    exit(0);
}