/*
** EPITECH PROJECT, 2020
** search_squares
** File description:
** bsq
*/

#include "my.h"
#include "bsq.h"

int colums_len(char *buffer)
{
    int i = 0;

    while (buffer[i] != '\n')
        i++;
    return i;
}

int lines_len(char *buffer)
{
    int i = 0;
    int count = 0;

    while (buffer[i] != '\0') {
        if (buffer[i] == '\n')
            count++;
        i++;
    }
    return count;
}

int buffer_size(char *pathname, int fd)
{
    struct stat buffer;

    stat(pathname, &buffer);
    return buffer.st_size;
}