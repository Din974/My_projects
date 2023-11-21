/*
** EPITECH PROJECT, 2020
** my_params_to_list
** File description:
** linked list
*/

#include "sokoban.h"
#include "my.h"

void my_put_in_list(xo_t **list, int y, int x, int state)
{
    xo_t *new_node = malloc(sizeof(xo_t));

    new_node->y = y;
    new_node->x = x;
    new_node->state = state;
    new_node->next = *list;
    *list = new_node;
}