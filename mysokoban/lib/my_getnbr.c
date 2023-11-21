/*
** EPITECH PROJECT, 2020
** my_getnbr
** File description:
** str to int
*/

int my_getnbr(char *str)
{
    int i = 0;
    int res = 0;
    int st = 1;

    while (str[i] != '\0' && (str[i] < '0' || str[i] > '9'))
            i++;
    if (i != 0 && str[i - 1] == '-')
        st = st * -1;
    while (str[i] >= '0' && str[i] <= '9') {
        res = (res * 10) + str[i] - 48;
        i++;
    }
    return res * st;
}
