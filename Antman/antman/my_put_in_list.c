/*
** EPITECH PROJECT, 2020
** my_params_to_list
** File description:
** linked list
*/

#include "antman.h"
#include "my.h"

void my_put_in_list(text_t **list, char *new_data, unsigned char letter_match)
{
    text_t *new_node = malloc(sizeof(text_t));

    new_node->data = new_data;
    new_node->data_match = letter_match;
    new_node->next = *list;
    *list = new_node;
}