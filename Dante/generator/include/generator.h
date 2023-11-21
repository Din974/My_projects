/*
** EPITECH PROJECT, 2020
** B-CPE-200-RUN-2-1-dante-luidgi.parinet
** File description:
** generator.h
*/

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>

typedef struct pos
{
    int y;
    int x;
    int y_max;
    int x_max;
}pos_t;

typedef struct available_cells
{
    int y;
    int x;
    pos_t about;
    struct available_cells *next;
}cells_t;

int **alloc_int_array(int **res, int x, int y);
void generator(int x, int y, int is_perfect);
int **fill_my_perfect_tab(int **tab, int x, int y);
int last_star_x(int **tab, int x_max);
int last_star_y(int **tab, int x_max);
int **fail_cases(int **tab, int x, int y);
cells_t *search_available_cells(int **tab, int y_max, int x_max);
void display_perfect_generator(int **tab, int x, int y);
int **prim_algo(int **tab, int x, int y);
void imperfect_generator(int x_max, int y_max);
void print_stars_errors(int x, int y);
void print_is_two(int x, int y);
void print_is_two_perf(int x, int y);