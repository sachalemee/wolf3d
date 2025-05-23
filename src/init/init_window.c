/*
** EPITECH PROJECT, 2025
** wolfengine
** File description:
** init_window.c
*/

#include "wolfengine.h"

int init_window(sfRenderWindow **window, sfVector2u win_dimension)
{
    sfVideoMode videomode = {0};
    static int mode = 0;

    videomode.height = WIN_HEIGHT;
    videomode.width = WIN_WIDTH;
    videomode.bitsPerPixel = WIN_BITS;
    if (mode % 2 == 0)
        *window = sfRenderWindow_create(videomode, WIN_TITLE,
            sfFullscreen, NULL);
    else
        *window = sfRenderWindow_create((sfVideoMode){
            win_dimension.x, win_dimension.y,
            WIN_BITS}, WIN_TITLE, sfResize, NULL);
    if (*window == NULL)
        return EXIT_FAIL;
    sfRenderWindow_setFramerateLimit(*window, WIN_FRAME);
    ++mode;
    return SUCCESS;
}
