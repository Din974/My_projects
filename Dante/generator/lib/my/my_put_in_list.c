/*
** EPITECH PROJECT, 2020
** my_params_to_list
** File description:
** linked list
*/

#include "../../include/generator.h"
#include "../../include/my.h"

void my_put_in_list(cells_t **list, int y, int x, pos_t about)
{
    cells_t *new_node = malloc(sizeof(cells_t));

    new_node->y = y;
    new_node->x = x;
    new_node->about = about;
    new_node->next = *list;
    *list = new_node;
}