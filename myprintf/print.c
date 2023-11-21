/*
** EPITECH PROJECT, 2020
** print
** File description:
** my_printf
*/

#include "my.h"
#include "my_printf.h"

int print_int(char flag, va_list arg, int i)
{
    struct print_int print[] = {
        {'c', &my_putchar_int},
        {'d', &my_put_nbr},
        {'i', &my_put_nbr},
        {'b', &binary_base},
        {'o', &octale_base},
        {'x', &hexa_base_lowercase},
        {'X', &hexa_base_uppercase},
        {'u', &my_put_nbr},
        {'p', &my_put_adress}
    };

    for (int x = 0; x != 9; x++) {
        if (flag == print[x].flag) {
            print[x].pt(va_arg(arg, int));
	    return i + 2;
        }
    }
    return i;
}

int print_str(char flag, va_list arg, int i)
{
    int x = 0;
    struct print_str print[] = {
        {'s', &my_putstr},
        {'S', &my_putstr_oct}
    };

    if (flag == '%') {
        my_putchar('%');
	return i + 2;
    }
    while (x != 2) {
        if (flag == print[x].flag) {
            print[x].pt(va_arg(arg, char *));
	    return i + 2;
        }
        x++;
    }
    return i;
}

int print_int_special(char flag, va_list arg, int i)
{
    struct print_int print[] = {
        {'c', &my_putchar_int},
        {'d', &my_put_nbr},
        {'i', &my_put_nbr},
        {'b', &binary_base},
        {'o', &octale_base},
        {'x', &hexa_base_lowercase},
        {'X', &hexa_base_uppercase},
        {'u', &my_put_nbr},
        {'p', &my_put_adress}
    };

    for (int x = 0; x != 9; x++) {
        if (flag == print[x].flag) {
            print[x].pt(va_arg(arg, int));
	    return i + 3;
        }
    }
    return i;
}

int print_str_special(char flag, va_list arg, int i)
{
    int x = 0;
    struct print_str print[] = {
        {'s', &my_putstr},
        {'S', &my_putstr_oct}
    };

    if (flag == '%') {
        my_putchar('%');
	return i + 3;
    }
    while (x != 2) {
        if (flag == print[x].flag) {
            print[x].pt(va_arg(arg, char *));
	    return i + 3;
        }
        x++;
    }
    return i;
}
