/*
** EPITECH PROJECT, 2025
** wolfengine
** File description:
** start.c
*/

#include <stddef.h>
#include "wolfengine.h"
#include "buttons.h"
#include "stdio.h"

int start(const char *_Nullable map_path)
{
    sys_data_t sys_data[] = {{0}};
    int tmp = 0;

    if (init_sys_data(sys_data, map_path) == FAILURE)
        return FAILURE;
    tmp = main_loop(sys_data);
    if (tmp == FAILURE)
        return FAILURE;
    if (tmp == EXIT_FAIL)
        return EXIT_FAIL;
    destroy_sys(*sys_data);
    return EXIT_SUCCESS;
}
