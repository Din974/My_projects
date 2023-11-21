/*
** EPITECH PROJECT, 2020
** B-CPE-200-RUN-2-1-matchstick-luidgi.parinet
** File description:
** matchstick.c
*/

#include "matchstick.h"
#include "my.h"

matchstick_t init_struct(matchstick_t match, int tab_len, int max_value)
{
    match.tab = init_tab(tab_len);
    match.line_max = tab_len;
    match.matches_max = max_value;
    match.player = 1;
    return match;
}

char **remove_matches(matchstick_t match)
{
    int last = last_match_of_the_str(match.tab[match.line]);

    for (int i = 0; i != match.matches; i++) {
        (match.tab[match.line][last] != '*') ?
        match.tab[match.line][last] = ' ' : 0;
        last--;
    }
    return match.tab;
}

int matchstick(int tab_len, int max_value)
{
    matchstick_t match = init_struct(match, tab_len, max_value);

    print_tab(match.tab, tab_len);
    while (tab_contain_pipe(match.tab) != 0) {
        if (match.player == 1) {
            my_printf("\nYour turn:\n");
            match = player1(match);
            if (match.line + 1 == -1 || match.matches == -1)
                return 0;
            my_printf("Player removed %d match(es) from line %d\n",
            match.matches, match.line + 1);
            print_tab(match.tab, tab_len);
        }else {
            my_printf("\nAI's turn...\n");
            match = random_bot(match);
            print_tab(match.tab, tab_len);
            match.player = 1;
        }
    }
    return victory(match);
}