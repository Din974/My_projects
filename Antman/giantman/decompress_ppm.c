/*
** EPITECH PROJECT, 2021
** decompress_ppm
** File description:
** decompress_ppm
*/

#include "my.h"
#include "antman.h"

int go_to_rgb_nb(char *file)
{
    int i = 0;
    int count = 0;

    while (file[i] != '\0') {
        if (file[i] == '\n')
            count++;
        i++;
        if (count == 3)
            break;
    }
    if (file[i] == '#') {
        while (file[i] != '\n')
            i++;
        i++;
    }
    return i;
}

dppm_t init_struct(dppm_t dppm, char *file)
{
    dppm.i = go_to_rgb_nb(file);
    dppm.count = 0;
    dppm.check = 0;
    return dppm;
}

dppm_t print_repetition(dppm_t dppm, char *file)
{
    int j = 0;

    while (file[dppm.i] != '|') {
        dppm.count = dppm.count * 10 + file[dppm.i] - '0';
        dppm.i++;
    }
    dppm.i++;
    j = dppm.i;
    while (dppm.count != 0) {
        my_putchar('\n');
        dppm.i = j;
        while (file[dppm.i] != '\n' && file[dppm.i] != '\0') {
            my_putchar(file[dppm.i]);
            dppm.i++;
        }
        dppm.i++;
        dppm.count--;
    }
    return dppm;
}

dppm_t print_correct_rgb(dppm_t dppm, char *file)
{

    if (dppm.check == 1)
        dppm = print_repetition(dppm, file);
    else {
        my_putchar('\n');
        dppm = get_single_nb(dppm, file);
        dppm.i++;
    }
    return dppm;
}

void decompress_ppm(char *file)
{
    dppm_t dppm = init_struct(dppm, file);
    int j = 0;

    while (j != dppm.i - 1) {
        my_putchar(file[j]);
        j++;
    }
    while (file[dppm.i] != '\0') {
        j = dppm.i;
        dppm.check = 0;
        while (file[j] != '\n') {
            if (file[j] == '|')
                dppm.check = 1;
            j++;
        }
        dppm = print_correct_rgb(dppm, file);
    }
    my_putchar('\n');
}