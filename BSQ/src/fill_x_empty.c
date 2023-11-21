/*
** EPITECH PROJECT, 2020
** fill_x_empty
** File description:
** bsq
*/

#include "my.h"
#include "bsq.h"

int check_line_quality(char *buffer)
{
    int i = 0;
    int count = 0;
    int check = colums_len(buffer);

    while (buffer[i] != '\0') {
        while (buffer[i] != '\n') {
            i++;
            count++;
        }
        if (count != check)
            return 1;
        count = 0;
        i++;
    }
    return 0;
}

int check_empty(char *buffer)
{
    int i = 0;

    while (buffer[i] != '\0') {
        if (buffer[i] == 'o')
            return 1;
        i++;
    }
    return 0;
}

int size_square_empty(char *buffer)
{
    int line_len = colums_len(buffer);
    int col_len = lines_len(buffer);

    if (line_len <= col_len)
        return line_len;
    return col_len;
}

void fill_x_empty(char *buffer)
{
    int i = -1;
    int size = size_square_empty(buffer);
    int count = 0;
    int lim = 0;

    if (check_empty(buffer) == 0 && size_square_empty(buffer) != 1) {
        while (buffer[++i] != '\0') {
            if ((count == 0 && count != size) ||
                (count != size && buffer[i - 1] == '\n')) {
                lim = -1;
                while (++lim != size) {
                    my_putchar('x');
                    i++;
                }
                count++;
            }
            my_putchar(buffer[i]);
        }
    }
}
