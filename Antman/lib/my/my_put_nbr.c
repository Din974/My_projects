/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** print number
*/

int my_put_nbr(int n);
void my_putchar(char c);

void int_min(int n)
{
    if (n == -2147483648) {
        my_put_nbr(n / 10);
        my_putchar('8');
    }
}

int my_put_nbr(int n)
{
    if (n < 0 && n != -2147483648) {
        n = n * -1;
        my_putchar('-');
    }
    if (n > 9) {
        my_put_nbr(n / 10);
        my_putchar(n % 10 + '0');
    }
    else if (n == 0 || n != -2147483648)
        my_putchar('0' + n);
    return 0;
}