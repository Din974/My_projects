/*
** EPITECH PROJECT, 2020
** B-CPE-200-RUN-2-1-dante-luidgi.parinet
** File description:
** main.c
*/

#include "generator.h"
#include "my.h"

int main(int ac, char **av)
{
    int x = 0;
    int y = 0;
    int is_perfect = 0;

    if ((ac != 3 && ac != 4) || (strisnum(av[1]) != 0) || strisnum(av[2]) != 0
    || atoi(av[1]) <= 0 || atoi(av[2]) <= 0)
        return 84;
    if (ac == 4 && my_strcmp(av[3], "perfect") == 0)
        is_perfect = 1;
    x = atoi(av[1]);
    y = atoi(av[2]);
    if (is_perfect == 1 && (x <= 2 || y == 1)) {
        print_stars_errors(x, y);
        print_is_two_perf(x, y);
        return 0;
    }
    generator(x, y, is_perfect);
}