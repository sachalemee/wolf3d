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
    static int mode = 0;

    if (mode % 2 == 0)
        *window = sfRenderWindow_create(videomode, WIN_TITLE,
        sfFullscreen, NULL);
    else
        *window = sfRenderWindow_create(videomode, WIN_TITLE,
            sfResize, NULL);
    if (*window == NULL)
        return EXIT_F;
    sfRenderWindow_setFramerateLimit(*window, WIN_FRAME);
    ++mode;
    return SUCCESS;
}
