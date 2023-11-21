/*
** EPITECH PROJECT, 2021
** my_strcat_char
** File description:
** antman
*/

#include "my.h"
#include "antman.h"

void my_put_in_list(text_t **list, char *new_data, unsigned char letter_match)
{
    text_t *new_node = malloc(sizeof(text_t));

    new_node->data = new_data;
    new_node->data_match = letter_match;
    new_node->next = *list;
    *list = new_node;
}

int contain(char *str, char c)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            return 1;
    }
    return 0;
}

char *my_strcat_char(char *str, char c)
{
    char *res = malloc(sizeof(char) * my_strlen(str) + 2);
    int i = 0;

    if (str == NULL) {
        res[0] = c;
        res[1] = '\0';
        return res;
    }
    while (str[i] != '\0') {
        res[i] = str[i];
        i++;
    }
    res[i] = c;
    res[i + 1] = '\0';
    return res;
}