/*
** EPITECH PROJECT, 2020
** printf
** File description:
** my_printf
*/

#ifndef MY_PRINTF_H_
#define MY_PRINTF_H_

#include <stdarg.h>
#include <stdlib.h>

struct print_int
{
    char flag;
    void(*pt)(int);
};

struct print_str
{
    char flag;
    void(*pt)(char *);
};

void my_printf(char *str, ...);
int fl(char flag);
int print_int(char flag, va_list arg, int i);
int print_str(char flag, va_list arg, int i);
int print_int_special(char flag, va_list arg, int i);
int print_str_special(char flag, va_list arg, int i);
void binary_base(int nb);
int len_res(int nb, int div);
void octale_base(int nb);
void my_putstr_oct(char *str);
void octale_base_ascii(int nb);
void hexa_base_lowercase(int nb);
void hexa_base_uppercase(int nb);
void my_put_adress(int nb);

#endif
