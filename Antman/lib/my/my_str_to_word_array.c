/*
** EPITECH PROJECT, 2020
** my_str_to_word_array
** File description:
** my_str_to_word_array
*/

#include <stdlib.h>
#include <stddef.h>

int check_char(char c)
{
    if (c == '\n' || c == '\0' || c == ' ')
        return 0;
    return 1;
}

int count_lines(char const *str)
{
    int i = 0;
    int count = 0;

    while (str[i] != '\0') {
        while (check_char(str[i]) == 0 && str[i] != '\0')
            i++;
        while (check_char(str[i]) == 1)
            i++;
        if (check_char(str[i - 1]) == 1)
            count++;
    }
    return count;
}

int my_new_size(char const *str, int j)
{
    int c = 0;

    while (check_char(str[j + c]) == 1)
        c++;
    return c;
}

char *new_str(char const *str, int i)
{
    int count = 0;
    int j = 0;
    char *dest = NULL;

    while (count < i || check_char(str[j]) == 0) {
        while (check_char(str[j]) == 1)
            j++;
        if (check_char(str[j - 1]) == 1)
            count++;
        j++;
    }
    dest = malloc(sizeof(char) * (my_new_size(str, j) + 1));
    count = 0;
    for (; check_char(str[j + count]) == 1 ; count++)
        dest[count] = str[j + count];
    dest[count] = '\0';
    return dest;
}

char **my_str_to_word_array(char const *str)
{
    int line = count_lines(str);
    char **tab = malloc(sizeof(char *) * (line + 1));
    int i = 0;

    while (i < line) {
        tab[i] = new_str(str, i);
        i++;
    }
    tab[i] = NULL;
    return tab;
}