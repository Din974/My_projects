/*
** EPITECH PROJECT, 2021
** lyrics_file
** File description:
** antman
*/

#include "my.h"
#include "antman.h"

int init_count(char *legend)
{
    int i = 0;
    int count = 0;

    while (legend[i] != '\0') {
        if (legend[i] == '=' && legend[i + 1] != '=')
            count++;
        i++;
    }
    return count;
}

text_t *init_list_giantman(char *legend)
{
    text_t *list = NULL;
    int count = init_count(legend);
    int i = 0;
    int x = 2;
    char *str = NULL;

    my_put_in_list(&list, "\n", legend[1]);
    while (i++ != count - 1) {
        while (legend[x] != '=') {
            str = my_strcat_char(str, legend[x]);
            (legend[x] == '=' && legend[x + 1] == '=') ? x += 2 : x++;
        }
        (legend[x] != '\0') ? my_put_in_list(&list, str, legend[x + 1]) : 0;
        str = NULL;
        x = x + 2;
    }
    return list;
}

void special_print(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        while (str[i] == ':') {
            my_putchar('\n');
            i++;
        }
        if (str[i] == '\0')
            return;
        my_putchar(str[i]);
    }
}

void char_matched(text_t *list, unsigned char match, char *lyrics, int i)
{
    while (list != NULL) {
        if (list->data_match == match && contain(list->data, ':') == 0) {
            my_putstr(list->data);
            if (lyrics[i + 1] != '\0')
                my_putchar(' ');
            return;
        }else if (list->data_match == match && contain(list->data, ':') == 1) {
            special_print(list->data);
            if (lyrics[i + 1] != '\0')
                my_putchar(' ');
            return;
        }
        list = list->next;
    }
}

void decompress_lyrics(char *file)
{
    int i = 0;
    char **tab = my_str_to_word_array(file);
    text_t *list = init_list_giantman(tab[0]);

    while (tab[1][i] != '\0') {
        char_matched(list, tab[1][i], tab[1], i);
        i++;
    }
}