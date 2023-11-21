/*
** EPITECH PROJECT, 2020
** B-CPE-200-RUN-2-1-dante-luidgi.parinet
** File description:
** my_strlen.c
*/

int my_strlen(char *buffer)
{
    int count = 0;

    for (int i = 0; buffer[i] != '\0'; i++)
        count += 1;
    return count;
}