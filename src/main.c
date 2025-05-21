/*
** EPITECH PROJECT, 2025
** wolfengine
** File description:
** main.c
*/

#include <stddef.h>
#include "wolfengine.h"

#include "hmap.h"

int main(int ac, char **av, char **)
{
    char *map_path = NULL;

    if (ac != 1 && ac != 2)
        return EXIT_FAIL;
    if (ac == 2)
        map_path = av[1];
    if (start(map_path) == FAILURE)
        return FAILURE;
    return EXIT_SUCCESS;
}
