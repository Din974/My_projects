/*
** EPITECH PROJECT, 2020
** my_str_isnum
** File description:
** return 1 if the string contains only digits
*/

int my_str_isnum(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if ((str[i] >= '0' && str[i] <= '9') || (str[i] == '\n'))
            i++;
        else
            return 1;
    }
    return 0;
}
