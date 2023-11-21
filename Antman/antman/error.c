/*
** EPITECH PROJECT, 2021
** error
** File description:
** error
*/

#include "my.h"
#include "antman.h"

int check_filetype(char *filetype)
{
    if ((filetype[0] != '1' && filetype[0] != '2' && filetype[0] != '3')
    || my_strlen(filetype) != 1)
        return 84;
    return 0;
}