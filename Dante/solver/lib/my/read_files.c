/*
** EPITECH PROJECT, 2020
** B-CPE-200-RUN-2-1-dante-luidgi.parinet
** File description:
** read_files.c
*/

#include "../../include/solver.h"

int nbr_bytes(char const *filepath)
{
    struct stat rd;

    (stat(filepath, &rd) == -1) ? exit(84) : 0;
    return (int)rd.st_size;
}

char *read_files(char **av)
{
    int buff_size = nbr_bytes(av[1]);
    char *buffer = NULL;
    int size = 0;
    int fd = open(av[1], O_RDONLY);

    (fd == -1) ? exit(84) : 0;
    buffer = malloc(sizeof(char) * buff_size + 1);
    size = read(fd, buffer, buff_size);
    (size == -1) ? exit(84) : 0;
    buffer[buff_size] = '\0';
    (strlen(buffer) == 0) ? exit(84) : 0;
    return buffer;
}