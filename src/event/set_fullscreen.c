/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** set_fullscreen.c
*/

#include "wolfengine.h"

int set_fullscreen(sys_data_t *sys, sfEvent event)
{
    if (is_keyboard_input(event, sfKeyF11)) {
        sfRenderWindow_destroy(sys->window);
        if (init_window(&sys->window, sys->win_dimension) == EXIT_FAIL)
            return EXIT_FAIL;
    }
    sys->win_dimension = sfRenderWindow_getSize(sys->window);
    return SUCCESS;
}
