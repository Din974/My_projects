/*
** EPITECH PROJECT, 2020
** B-CPE-200-RUN-2-1-dante-luidgi.parinet
** File description:
** rand_without_time.c
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int rand_getpid(int max)
{
    srand(getpid());
    return rand() % max;
}