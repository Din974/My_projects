/*
** EPITECH PROJECT, 2020
** my_strncmp
** File description:
** compare 2 strings with a int n paramater
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    while (i != n) {
        if (s1[i] == s2[i])
            i++;
        else
            return s1[i] - s2[i];
    }
    return 0;
}
