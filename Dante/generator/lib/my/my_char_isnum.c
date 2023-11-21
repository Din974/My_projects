/*
** EPITECH PROJECT, 2020
** my_str_isnum
** File description:
** return 1 if the string contains only digits
*/

int my_char_isnum(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    else
        return 0;
}
