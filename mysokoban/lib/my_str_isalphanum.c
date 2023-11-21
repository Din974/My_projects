/*
** EPITECH PROJECT, 2020
** my_str_isalpha_num
** File description:
** return 1 if the string contains only alphabetical characters
*/

int my_str_isalphanum(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if ((str[i] >= 'a' && str[i] <= 'z') ||
            (str[i] >= 'A' && str[i] <= 'Z') ||
            (str[i] >= '0' && str[i] <= '9') ||
            (str[i] == '_'))
            i++;
        else
            return 1;
    }
    return 0;
}
