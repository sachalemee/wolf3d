/*
** EPITECH PROJECT, 2024
** swap
** File description:
** swaps the value of a and b using xor because logic gates are cool
*/

#include <stddef.h>
#include "my.h"

void my_swap(void *a, void *b, size_t size)
{
    char *bytecode_a = (char *)a;
    char *bytecode_b = (char *)b;

    for (size_t i = 0; i < size; i++)
        swap_char(&(bytecode_a[i]), &(bytecode_b[i]));
}
