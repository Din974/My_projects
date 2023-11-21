/*
** EPITECH PROJECT, 2020
** main
** File description:
** bsq
*/

#include "my.h"
#include "bsq.h"

void print_res(char **res)
{
    int i = 0;
    int len = my_strlen(res[0]);

    while (res[i] != NULL) {
        write(1, res[i], len);
        my_putchar('\n');
        i++;
    }
}

int check_obstacle_alone(char *buffer)
{
    int i = 0;

    while (buffer[i] != '\0') {
        if (buffer[i] != 'o' && buffer[i] != '\n')
            return 1;
        i++;
    }
    return 0;
}

void print_special(char *buffer)
{
    int i = 0;
    int x = 0;

    if (check_obstacle_alone(buffer) == 0)
        my_putstr(buffer);
    else if (lines_len(buffer) == 1 || colums_len(buffer) == 1) {
        while (buffer[i] != '\0') {
            if (x == 0 && buffer[i] == '.') {
                my_putchar('x');
                x++;
                i++;
            }
            if (buffer[i] == '\0')
                break;
            my_putchar(buffer[i]);
            i++;
        }
    }
}
