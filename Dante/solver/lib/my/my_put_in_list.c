/*
** EPITECH PROJECT, 2020
** my_params_to_list
** File description:
** linked list
*/

#include "../../include/solver.h"
#include "../../include/my.h"

void my_put_in_list(path_t **list, pos_t pos, pos_t about, int is_visited)
{
    path_t *new_node = malloc(sizeof(path_t));

    new_node->y = pos.y;
    new_node->x = pos.x;
    new_node->about = about;
    new_node->is_visited = is_visited;
    new_node->next = *list;
    *list = new_node;
}