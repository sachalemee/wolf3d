/*
** EPITECH PROJECT, 2024
** swap_char
** File description:
** swaps the value of two char variables
*/

void swap_char(char *a, char *b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}
