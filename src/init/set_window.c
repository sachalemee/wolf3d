/*
** EPITECH PROJECT, 2025
** wolfengine
** File description:
** set_window.c
*/

#include "wolfengine.h"

sfRenderWindow *set_window(void)
{
    sfRenderWindow *window = {0};
    sfVideoMode videomode = sfVideoMode_getDesktopMode();

    window = sfRenderWindow_create(videomode, WIN_TITLE, sfFullscreen, NULL);
    if (window == NULL)
        return NULL;
    sfRenderWindow_setFramerateLimit(window, WIN_FRAME);
    return window;
}
