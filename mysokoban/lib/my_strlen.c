/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** len of a string
*/

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return i;
}