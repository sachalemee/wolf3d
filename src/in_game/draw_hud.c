/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-marin.jeunot
** File description:
** draw_hud
*/

#include "wolfengine.h"

void draw_hud(hud_t *hud, sfRenderWindow *win)
{
    sfRenderWindow_drawSprite(win, hud->hud_sprite, NULL);
}
