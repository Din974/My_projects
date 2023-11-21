/*
** EPITECH PROJECT, 2021
** main
** File description:
** sokoban
*/

#include "my.h"
#include "sokoban.h"

void usage(void)
{
    my_printf("USAGE\n");
    my_printf("      ./my_sokoban map\n");
    my_printf("DESCRIPTION\n");
    my_printf("      map file representing the warehouse map, containing ‘#’ ");
    my_printf("for walls, ");
    my_printf("\n     ‘P’ for the player, ‘X’ for boxes and ‘O’ for ");
    my_printf("storage locations.\n");
}