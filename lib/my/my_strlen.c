/*
** EPITECH PROJECT, 2024
** strlen
** File description:
** returns the len of the string
*/

#include "./my.h"

int my_strlen(char const *str)
{
    int count = 0;

    while (str[count] != '\0')
        count++;
    return count;
}
