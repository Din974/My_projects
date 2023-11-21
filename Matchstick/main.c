/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include <stdbool.h>
#include "my.h"
#include "matchstick.h"

static bool args_are_correct(int ac, char **av);

int main(int ac, char **av)
{
    if (args_are_correct(ac, av) == true)
        return 84;
    return matchstick(my_getnbr(av[1]), my_getnbr(av[2]));
}

static bool args_are_correct(int ac, char **av)
{
    return (
        ac != 3
        || my_str_isnum(av[1]) == 1
        || my_str_isnum(av[2]) == 1
        || my_getnbr(av[1]) <= 1
        || my_getnbr(av[1]) > 100
        || my_getnbr(av[2]) <= 0
    );
}