/*
** EPITECH PROJECT, 2020
** my_revstr
** File description:
** my_revstr
*/

int my_strlen(char *str);

char *my_revstr(char *str)
{
    int end = my_strlen(str) - 1;
    int start = 0;
    int i = 0;
    char stock;

    while (i != my_strlen(str) / 2) {
        stock = str[start];
        str[start] = str[end];
        str[end] = stock;
        start++;
        end--;
        i++;
    }
    return str;
}
