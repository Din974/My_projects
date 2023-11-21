/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** my_printf
*/

#include "my.h"
#include "my_printf.h"

int fl(char flag)
{
    if (flag == 'd' || flag == 'i' || flag == 'c' || flag == 'b' ||
        flag == 'o' || flag == 'x' || flag == 'X' || flag == 'u' ||
        flag == 'p' || flag == 's' || flag == '%' || flag == 'S')
        return 1;
    return -1;
}

void my_printf(char *str, ...)
{
    int i = 0;
    int x;
    va_list arg;

    va_start(arg, str);
    while (str[i] != '\0') {
        if (str[i] == '%' && fl(str[i + 1]) == 1) {
            i = print_str(str[i + 1], arg, i);
            i = print_int(str[i + 1], arg, i);
        }else if (str[i] == '%' && str[i + 1] == '#' && fl(str[i + 2] == 1)) {
            i = print_str_special(str[i + 2], arg, i);
            i = print_int_special(str[i + 2], arg, i);
        }else {
            my_putchar(str[i]);
            i++;
        }
        if (str[i] == '\0')
            break;
    }
    va_end(arg);
}
