/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** calls.c
*/

#include "wolfengine.h"
#include "buttons.h"
#include <stdio.h>

void close_menu(sys_data_t *sys)
{
    sys->is_running = false;
}

static void buttons_event(sys_data_t *sys, sfEvent event)
{
    for (int i = 0; i < NB_BUTTONS_MENU; i++)
        buttons_status(sys->window,
            sys->scene.menu.buttons[i], event, sys);
}

int events_menu(sys_data_t *sys)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(sys->window, &event)) {
        close_window(sys, event);
        if (set_fullscreen(sys, event) == EXIT_FAIL)
            return EXIT_FAIL;
        buttons_event(sys, event);
    }
    return EXIT_SUCCESS;
}
