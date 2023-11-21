/*
** EPITECH PROJECT, 2020
** my_rev_size
** File description:
** reverse the orders of the lists element
*/

#include "../../include/solver.h"

void my_rev_list(path_t **begin)
{
    struct path_finding *old = NULL;
    struct path_finding *actual = *begin;
    struct path_finding *next = NULL;

    while (actual != NULL) {
        next = actual->next;
        actual->next = old;
        old = actual;
        actual = next;
    }
    *begin = old;
}