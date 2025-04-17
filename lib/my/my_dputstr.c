/*
** EPITECH PROJECT, 2024
** my_putstr
** File description:
** puts the next arg in the stdout
*/

#include <unistd.h>

int my_dputstr(int fd, const char *tput)
{
    int i = 0;

    for (; tput[i] != '\0'; i += write(fd, &tput[i], 1));
    return i;
}
