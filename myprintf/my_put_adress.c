/*
** EPITECH PROJECT, 2020
** my_putstr_oct
** File description:
** my_putstr_oct
*/

#include "my.h"
#include "my_printf.h"

void my_put_adress(int nb)
{
    my_putstr("0x");
    hexa_base_lowercase(nb);
}