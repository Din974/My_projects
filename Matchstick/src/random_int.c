/*
** EPITECH PROJECT, 2020
** B-CPE-200-RUN-2-1-matchstick-luidgi.parinet
** File description:
** random_int.c
*/

#include "matchstick.h"
#include "my.h"

int get_random_int(int rand_max)
{
    srandom(time(NULL));
    return random() % rand_max;
}