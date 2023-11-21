/*
** EPITECH PROJECT, 2021
** lyrics_file
** File description:
** antman
*/

#include "my.h"
#include "antman.h"

int check_if_elem_exist(text_t *list, char *elem)
{
    while (list != NULL) {
        if (my_strcmp(list->data, elem) == 0)
            return 0;
        list = list->next;
    }
    return 1;
}

text_t *init_text(char **tab)
{
    text_t *list = NULL;
    int i = 0;
    unsigned char letter = 33;
    int scale = 0;

    while (tab[i] != NULL) {
        if (check_if_elem_exist(list, tab[i]) == 1) {
            my_put_in_list(&list, tab[i], letter + scale);
            scale += 1;
            if (letter + scale == 127 || letter + scale == ':')
                scale += 1;
        }
        i++;
    }
    my_put_in_list(&list, "\n", ':');
    return list;
}

unsigned char print_data_match(text_t *list, char *elem)
{
    char res;

    while (list != NULL) {
        if (my_strcmp(list->data, elem) == 0)
            res = list->data_match;
        list = list->next;
    }
    return res;
}

char *conv_new_line(char *file)
{
    for (int i = 0; file[i] != '\0'; i++) {
        if (file[i] == '\n')
            file[i] = ':';
    }
    return file;
}

void compress_lyrics(char *file)
{
    char **tab = my_str_to_word_array(file);
    text_t *list = init_text(tab);
    text_t *tmp = list;

    for (; tmp != NULL; tmp = tmp->next) {
        my_putstr(tmp->data);
        my_putchar('=');
        my_putchar(tmp->data_match);
    }
    my_putchar('\n');
    for (int i = 0; tab[i] != NULL; i++)
        my_putchar(print_data_match(list, tab[i]));
}