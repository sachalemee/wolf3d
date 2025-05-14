/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-marin.jeunot
** File description:
** call_setting
*/


#include "wolfengine.h"
#include "buttons.h"
#include <stdio.h>

void return_to_menu(sys_data_t *sys)
{
    sys->scene.state = STATE_MENU;
}

static void buttons_event_setting(sys_data_t *sys, sfEvent event)
{
    for (int i = 2; i < NB_BUTTONS_SETTINGS; i++)
        buttons_status(sys->window,
            sys->scene.setting_screen.buttons[i], event, sys);
}

int events_setting(sys_data_t *sys)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(sys->window, &event)) {
        close_window(sys, event);
        if (set_fullscreen(sys, event) == EXIT_F)
            return EXIT_F;
        buttons_event_setting(sys, event);
    }
    return EXIT_S;
}

