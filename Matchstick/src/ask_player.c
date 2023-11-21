/*
** EPITECH PROJECT, 2020
** B-CPE-200-RUN-2-1-matchstick-luidgi.parinet
** File description:
** ask_player.c
*/

#include "my.h"
#include "matchstick.h"

int ask_line(matchstick_t match)
{
    char *ask = NULL;
    size_t len = 0;
    int line = 0;

    my_printf("Line: ");
    if (getline(&ask, &len, stdin) == -1)
        return -1;
    if (my_str_isnum(ask) == 1) {
        my_printf("Error: invalid input (positive number expected)\n");
        return (ask_line(match));
    }
    line = my_getnbr(ask);
    if (line == 0 || line > match.line_max) {
        my_printf("Error: this line is out of range\n");
        return (ask_line(match));
    }
    return line;
}

int ask_matches(matchstick_t match, char *line)
{
    char *ask = NULL;
    size_t len = 0;
    int matches = 0;

    my_printf("Matches: ");
    if (getline(&ask, &len, stdin) == -1)
        return -1;
    if (my_str_isnum(ask) == 1) {
        my_printf("Error: invalid input (positive number expected)\n");
        return -2;
    }
    matches = my_getnbr(ask);
    if (check_ask_matches_errors(match, matches, line) == 1)
        return -2;
    return matches;
}