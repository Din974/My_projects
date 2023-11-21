/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** CPool3
*/

void my_putchar(char c);

void my_put_nbr(int nb)
{
    int count = 1;
    int disp = 0;

    if (nb < 0) {
      my_putchar('-');
      nb = nb * -1;
    }
    while ((nb/count) > 9)
        count = count * 10;
    while (count != 0) {
        disp = 48 + (nb/count);
        nb = nb % count;
        my_putchar(disp);
        count = count / 10;
    }
}
