/*
** EPITECH PROJECT, 2029
** matchstick.h
** File description:
** matchstick.h
*/

#ifndef matchstick_H_
#define matchstick_H_

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>

typedef struct matchstick
{
    char **tab;
    int player;
    int line_max;
    int matches_max;
    int line;
    int matches;
}matchstick_t;

char **init_tab(int tab_len);
void print_tab(char **tab, int tab_len);
int matchstick(int tab_len, int max_value);
int get_pipe_nbr(char *str);
int tab_contain_pipe(char **tab);
int check_ask_matches_errors(matchstick_t match, int matches, char *line);
int last_match_of_the_str(char *str);
matchstick_t player1(matchstick_t match);
int ask_line(matchstick_t match);
int ask_matches(matchstick_t match, char *line);
int get_random_int(int rand_max);
char **remove_matches(matchstick_t match);
matchstick_t random_bot(matchstick_t match);
int victory(matchstick_t match);
int matches_value(matchstick_t match, int nbr_pipes);

#endif