/*
** EPITECH PROJECT, 2020
** main
** File description:
** bsq
*/

#include "my.h"
#include "bsq.h"

char *read_buffer(char *pathname, int fd, int size)
{
    char *buff;

    buff = malloc(sizeof(char) * size + 1);
    read(fd, buff, size);
    buff[size] = '\0';
    return buff;
}

char *check_number_line(char *buffer)
{
    int i = 0;
    char *first_line = malloc(sizeof(char) * (colums_len(buffer) + 1));

    while (buffer[i] != '\n') {
        first_line[i] = buffer[i];
        i++;
    }
    first_line[i] = '\0';
    return first_line;
}

int check_nbr_match(char *buffer, int nbr_lines)
{
    int check = my_getnbr(check_number_line(buffer));

    if (check == nbr_lines - 1)
        return 0;
    return 1;
}

char *delete_first_line(char *buff)
{
    while ((*buff >= '0' && *buff <= '9') || *buff == '\n')
        buff++;
    return buff;
}

int main(int ac, char **av)
{
    int fd = open(av[1], O_RDONLY);
    char *buffer;

    if (fd == -1 || ac != 2 || buffer_size(av[1], fd) == 0)
        return 84;
    buffer = read_buffer(av[1], fd, buffer_size(av[1], fd));
    if (check_nbr_match(buffer, lines_len(buffer)) == 1)
        return 84;
    buffer = delete_first_line(buffer);
    if (lines_len(buffer) == 1 || colums_len(buffer) == 1 ||
        check_obstacle_alone(buffer) == 0 || check_empty(buffer) == 0) {
        fill_x_empty(buffer);
        print_special(buffer);
        return 0;
    }
    if (check_line_quality(buffer) == 1)
        return 84;
    print_res(final_tab(check_greater_square(buffer), buffer));
    return 0;
}
