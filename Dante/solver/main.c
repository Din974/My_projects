/*
** EPITECH PROJECT, 2020
** B-CPE-200-RUN-2-1-dante-luidgi.parinet
** File description:
** main.c
*/

#include "solver.h"
#include "my.h"

int buffer_y(char *buffer)
{
    int count = 0;

    for (int i = 0; buffer[i] != '\0'; i++)
        if (buffer[i] == '\n')
            count += 1;
    return count + 1;
}

int str_contain_char(char *str, char to_search)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == to_search)
            return 0;
    return 1;
}

int buffer_x(char *buffer)
{
    int count = 0;

    if (str_contain_char(buffer, '\n') == 1) {
        for (int i = 0; buffer[i] != '\0'; i++)
            count += 1;
    }else
        for (int i = 0; buffer[i] != '\n'; i++)
            count += 1;
    return count;
}

int check_map(char *buffer)
{
    for (int i = 0; buffer[i] != '\0'; i++)
        if (buffer[i] != 'X' && buffer[i] != '*' && buffer[i] != '\n')
            return 84;
    return 0;
}

int main(int ac, char **av)
{
    char *buffer = NULL;

    if (ac != 2)
        return 84;
    buffer = read_files(av);
    if (check_map(buffer) == 84 || buffer[my_strlen(buffer) - 1] == '\n') {
        write(2, "Invalid map\n", 12);
        return 84;
    }
    if (buffer[0] == 'X' || buffer[my_strlen(buffer) - 1] == 'X') {
        printf("no solution found");
        return 0;
    }
    solver(buffer, buffer_x(buffer), buffer_y(buffer));
    return 0;
}