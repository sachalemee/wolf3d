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

    if (init_sys_data(sys_data, map_path) == FAILURE)
        return EXIT_FAIL;
    if (main_loop(sys_data) == FAILURE)
        return EXIT_FAIL;
    destroy_sys(*sys_data);
    return EXIT_SUCCESS;
}
