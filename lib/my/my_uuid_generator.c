/*
** EPITECH PROJECT, 2025
** init_things.c
** File description:
** things for the wolfengine
*/
#include "my.h"
#include <stdlib.h>

void rand128(__int128_t *dest)
{
    int *to_set = (void *)dest;

    for (size_t i = 0; i < sizeof(__int128_t) / sizeof(int); i++) {
        to_set[i] = rand();
    }
}

void my_uuid_generator(__int128_t *dest)
{
    int randval = rand();
    char *hash_str = (void *)&randval;
    size_t len = sizeof(typeof(randval));
    __int128_t randbuffer = 0;

    rand128(dest);
    for (size_t i = 0; i < len; i++) {
        rand128(&randbuffer);
        *dest ^= hash_str[i];
        *dest *= randbuffer;
    }
}
