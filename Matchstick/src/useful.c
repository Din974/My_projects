/*
** EPITECH PROJECT, 2020
** B-CPE-200-RUN-2-1-matchstick-luidgi.parinet
** File description:
** useful.c
*/

#include "matchstick.h"
#include "my.h"

int get_pipe_nbr(char *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '|')
            count++;
    }
    return count;
}

int tab_contain_pipe(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++) {
        if (get_pipe_nbr(tab[i]) != 0)
            return 1;
    }
    return 0;
}

int check_ask_matches_errors(matchstick_t match, int matches, char *line)
{
    if (matches == 0) {
        my_printf("Error: you have to remove at least one match\n");
        return 1;
    }
    if (matches > match.matches_max) {
        my_printf("Error: you cannot remove more than %d", match.matches_max);
        my_printf(" matches per turn\n");
        return 1;
    }
    if (matches > get_pipe_nbr(line)) {
        my_printf("Error: not enough matches on this line\n");
        return 1;
    }
    return 0;
}

int last_match_of_the_str(char *str)
{
    int last = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '|')
            last = i;
    }
    return last;
}

int matches_value(matchstick_t match, int nbr_pipes)
{
    int max = match.matches_max;

    while (max != 1) {
        if (nbr_pipes - max >= 1 && max <= match.matches_max)
            return max;
        max--;
    }
    return max;
}