/*
** EPITECH PROJECT, 2021
** main
** File description:
** antman main
*/

#include "antman.h"
#include "my.h"

int main(int ac, char **av)
{
    int fd;
    char *file;
    int check = 0;
    struct stat buff;

    if (ac != 3 || check_filetype(av[2]) == 84) {
        write(2, "Invalid arguments\n", 18);
        return 84;
    }
    fd = open(av[1], O_RDONLY);
    check = stat(av[1], &buff);
    if (fd < 0 || check < 0) {
        write(2, "Invalid file\n", 13);
        return 84;
    }
    file = malloc(sizeof(char) * buff.st_size + 1);
    if (read(fd, file, buff.st_size) == -1 || file == NULL ||
        my_strlen(file) == 0)
        return 84;
    giantman(file, av[2][0]);
}