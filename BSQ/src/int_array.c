/*
** EPITECH PROJECT, 2020
** int_array
** File description:
** bsq
*/

#include "my.h"
#include "bsq.h"

int **alloc_int_array(int **res, int lines_len, int colums_len)
{
    int i = 0;
    int x = 0;

    res = malloc(sizeof(int *) * (lines_len + 1));
    while (i != lines_len) {
        res[i] = malloc(sizeof(int) * (colums_len + 1));
        i++;
    }
    return res;
}

int **str_to_int_array(char *buffer)
{
    char **tab = my_str_to_word_array(buffer);
    int **res = alloc_int_array(res, lines_len(buffer), colums_len(buffer));
    int i = 0;
    int x = 0;

    while (tab[i] != NULL) {
        x = 0;
        while (tab[i][x] != '\0') {
            if (tab[i][x] == '.')
                res[i][x] = 1;
            else
                res[i][x] = 0;
            x++;
        }
        i++;
    }
    return res;
}

int actual_int(int actual, int smaller)
{
    if (actual == 0)
        return 0;
    else
        return smaller + 1;
}

int smaller(int left, int top_left, int top)
{
    if ((left < top_left && left < top) ||
        (left == top_left && left < top) ||
        (left == top && top < top_left))
        return left;
    if ((top_left < left && top_left < top) ||
        (top_left == top && top_left < left))
        return top_left;
    if (top < left && top < top_left)
        return top;
    return left;
}

int **check_greater_square(char *buffer)
{
    int **tab = str_to_int_array(buffer);
    int x = 1;
    int y = 0;
    int left = 0;
    int top_left = 0;
    int top = 0;
    int count = 0;

    while (++y != lines_len(buffer)) {
        x = 1;
        count = 0;
        while (++count != colums_len(buffer) - 1) {
            left = tab[y][x - 1];
            top_left = tab[y - 1][x - 1];
            top = tab[y - 1][x];
            tab[y][x] = actual_int(tab[y][x], smaller(left, top_left, top));
            x++;
        }
    }
    return tab;
}