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

void handle_slider_events(setting_screen_t *setting,
    const sfEvent *event, sfRenderWindow *window)
{
    sfVector2i mousePos = {0, 0};
    sfFloatRect bounds = {0.0f, 0.0f, 0.0f, 0.0f};

    if (event->type == sfEvtMouseButtonPressed
        && event->mouseButton.button == sfMouseLeft) {
        mousePos = sfMouse_getPositionRenderWindow(window);
        bounds = sfCircleShape_getGlobalBounds(setting->slider_cursor);
        if (sfFloatRect_contains(&bounds, mousePos.x, mousePos.y)) {
            setting->isDragging = 1;
        }
    }
    if (event->type == sfEvtMouseButtonReleased
        && event->mouseButton.button == sfMouseLeft)
        setting->isDragging = 0;
}

int events_setting(sys_data_t *sys)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(sys->window, &event)) {
        close_window(sys, event);
        handle_slider_events(&(sys->scene.setting_screen),
            &event, sys->window);
        if (set_fullscreen(sys, event) == EXIT_FAIL)
            return EXIT_FAIL;
        buttons_event_setting(sys, event);
    }
    return EXIT_SUCCESS;
}
