/*
** EPITECH PROJECT, 2020
** my_char_is_printable
** File description:
** return 0 if the character is printable
*/

int my_char_isprintable(char c)
{
    if ((c >= 0 && c <= 31) || c == 127)
        return 1;
    return 0;
}
