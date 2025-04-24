/*
** EPITECH PROJECT, 2025
** wolfengine
** File description:
** init_window.c
*/

#include "wolfengine.h"

int init_window(sfRenderWindow **window)
{
    sfVideoMode videomode = sfVideoMode_getDesktopMode();

    *window = sfRenderWindow_create(videomode, WIN_TITLE, sfFullscreen, NULL);
    if (*window == NULL)
        return FAILURE;
    sfRenderWindow_setFramerateLimit(*window, WIN_FRAME);
    return SUCCESS;
}
