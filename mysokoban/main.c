/*
** EPITECH PROJECT, 2021
** main
** File description:
** sokoban
*/

#include "my.h"
#include "sokoban.h"

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
    return buffer;
}

int check_valid_map(char *str)
{
    int count_p = 0;
    int count_x = 0;
    int count_o = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ' && str[i] != '\n' && str[i] != '#' &&
            str[i] != 'X' && str[i] != 'O' && str[i] != 'P') {
            write(2, "Invalid map\n", 12);
            return 84;
        }
        (str[i] == 'P') ? count_p += 1 : 0;
        (str[i] == 'X') ? count_x += 1 : 0;
        (str[i] == 'O') ? count_o += 1 : 0;
    }
    if (count_p != 1 || count_x != count_o) {
        write(2, "Invalid map\n", 12);
        return 84;
    }
    return 0;
}

int main(int ac, char **av)
{
    char *buffer = NULL;

    if (ac != 2)
        return 84;
    if (my_strcmp(av[1], "-h") == 0) {
        usage();
        return 0;
    }
    buffer = read_files(av);
    (check_valid_map(buffer) == 84) ? exit(84) : 0;
    sokoban(buffer);
    return 0;
}

