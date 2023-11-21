/*
** EPITECH PROJECT, 2020
** my_str_to_word_array
** File description:
** convert a char * to char **
*/

#include <stdlib.h>
#include <stddef.h>

int my_char_isalpha(char c);

int my_char_isnum(char c);

int check_alphanum(char c)
{
    if (c == '.' || c == 'o')
        return 1;
    else
        return 0;
}

int my_array_len(char const *str)
{
    int i = 0;
    int res = 0;

    while (str[i] != '\0') {
        while (check_alphanum(str[i]) == 0 && str[i] != '\0')
            i++;
        while (check_alphanum(str[i]) == 1)
            i++;
        if (check_alphanum(str[i - 1]) == 1)
            res++;
    }
    return res;
}

int my_word_len(char const *str, int x)
{
    int res = 0;

    while (check_alphanum(str[x + res]) == 1)
        res++;
    return res;
}

char *create_str(char const *str, int y)
{
    int x = 0;
    int scale = 0;
    char *dest = NULL;

    while (scale < y || check_alphanum(str[x]) == 0) {
        while (check_alphanum(str[x]) == 1)
            x++;
        if (check_alphanum(str[x - 1]) == 1)
            scale++;
        x++;
    }
    dest = malloc(sizeof(char) * (my_word_len(str, x) + 1));
    scale = 0;
    for (; check_alphanum(str[x + scale]) == 1; scale++)
        dest[scale] = str[x + scale];
    dest[scale] = '\0';
    return dest;
}

char **my_str_to_word_array(char *str)
{
    int array_len = my_array_len(str);
    char **dest = malloc(sizeof(char *) * (array_len + 1));
    int y = 0;

    while (y < array_len) {
        dest[y] = create_str(str, y);
        y++;
    }
    dest[y] = NULL;
    return dest;
}
