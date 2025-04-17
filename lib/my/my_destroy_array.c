/*
** EPITECH PROJECT, 2024
** my_destroy_array.c
** File description:
** destroys any null terminated array of pointers of depth 'depth'
*/

#include "my.h"

void my_destroy_array(void *start, size_t depth)
{
    if (depth == 0)
        return;
    if (depth == 1) {
        free(start);
        return;
    }
    for (size_t i = 0; ((char **)start)[i] != NULL; i++) {
        my_destroy_array(((char **)start)[i], depth - 1);
        free(start);
    }
}
