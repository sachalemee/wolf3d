/*
** EPITECH PROJECT, 2025
** my_strsplit.c
** File description:
** splits a string using the separators
*/

#include "./my.h"

void free_fstrsplit(char **to_free)
{
    if (to_free != NULL) {
        free(to_free[0]);
        free(to_free);
    }
}

// malloc size has +2 :
// +1 for null termination
// +1 because count instances is 1 short of the number of words (ex :
//     'hello;hi' => 2 words but 1 sep)
char **my_fstrsplit(char *to_split, const char *sep)
{
    char **dest = malloc((count_instances(to_split, sep) + 2)
        * sizeof(char *));
    size_t array_index = 1;

    if (dest == NULL)
        return NULL;
    dest[0] = to_split;
    for (size_t i = 0; to_split[i] != '\0'; i++) {
        if (my_contains(sep, to_split[i])) {
            dest[array_index] = &(to_split[i + 1]);
            to_split[i] = '\0';
            array_index++;
        }
    }
    dest[array_index] = NULL;
    return dest;
}
