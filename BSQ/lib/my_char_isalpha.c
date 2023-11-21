/*
** EPITECH PROJECT, 2020
** my_char_isalpha
** File description:
** return 1 if the string contains only alphabetical characters
*/

int my_char_isalpha(char c)
{
    int i = 0;

    if ((c >= 'a' && c <= 'z') ||
        (c >= 'A' && c <= 'Z'))
        return 1;
    else
        return 0;
}
