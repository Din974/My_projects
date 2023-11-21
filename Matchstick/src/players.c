/*
** EPITECH PROJECT, 2020
** B-CPE-200-RUN-2-1-matchstick-luidgi.parinet
** File description:
** players.c
*/

#include "matchstick.h"
#include "my.h"

matchstick_t player1(matchstick_t match)
{
    match.line = ask_line(match) - 1;
    if (match.line + 1 == -1)
        return match;
    match.matches = ask_matches(match, match.tab[match.line]);
    if (match.matches == -1)
        return match;
    if (match.matches == -2)
        return player1(match);
    match.tab = remove_matches(match);
    match.player = 2;
    return match;
}

int random_line_bot(matchstick_t match)
{
    for (int line = 0; match.tab[line] != NULL; line++)
        if (get_pipe_nbr(match.tab[line]) > 1)
            return line;
    for (int line = 0; match.tab[line] != NULL; line++)
        if (get_pipe_nbr(match.tab[line]) == 1)
            return line;
}

int random_match_bot(matchstick_t match)
{
    int matches = 0;
    int nbr_pipes = get_pipe_nbr(match.tab[match.line]);

    if (nbr_pipes > 1) {
        if (nbr_pipes - match.matches_max >= 1 &&
            nbr_pipes - match.matches_max <= match.matches_max)
            matches = nbr_pipes - match.matches_max;
        else
            matches = matches_value(match, nbr_pipes);
    }else
        return 1;
    return matches;
}

matchstick_t random_bot(matchstick_t match)
{
    match.line = random_line_bot(match);
    match.matches = random_match_bot(match);
    match.tab = remove_matches(match);
    my_printf("AI removed %d match(es) from line %d\n",
        match.matches, match.line + 1);
    return match;
}

int victory(matchstick_t match)
{
    if (match.player == 1) {
        my_printf("I lost... snif... but I'll get you next time!!\n");
        return 1;
    }
    my_printf("You lost, too bad...\n");
    return 2;
}