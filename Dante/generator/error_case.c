/*
** EPITECH PROJECT, 2020
** B-CPE-200-RUN-2-1-dante-luidgi.parinet
** File description:
** error_case.c
*/

#include <stdio.h>

void print_stars_errors(int x, int y)
{
    int index = 0;

    if (y == 1) {
        while (index != x - 1) {
            printf("*\n");
            index++;
        }
        printf("*");
    } else if (x == 1) {
        while (index != y) {
            printf("*");
            index++;
        }
    }
}

void print_is_two(int x, int y)
{
    int index = 0;

    if (x == 2 &&  y != 1) {
        while (index != y - 1) {
            printf("**\n");
            index++;
        }
        printf("**");
    }
}

void print_is_two_perf(int x, int y)
{
    int index = 0;

    if (x == 2 && y != 1) {
        while (index != y - 1) {
            printf("*X\n");
            index++;
        }
        printf("**");
    }
}