/*
** EPITECH PROJECT, 2020
** my_getnbr
** File description:
** retrieve a number in a string
*/

int my_getnbr(char *str)
{
    int i = 0;
    int neg = 1;
    int n = 0;

    while (str[i] != '\0' && (str[i] == '+' || str[i] == '-')) {
        if (str[i] == '-')
            neg = neg * -1;
        i++;
    }
    while (str[i] >= 48 && str[i] <= 57) {
        n = (n * 10) + str[i] - 48;
        i++;
    }
    return (n * neg);
}