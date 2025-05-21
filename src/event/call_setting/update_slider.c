/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-marin.jeunot
** File description:
** update_slider
*/

#include "wolfengine.h"
#include "buttons.h"

void update_slider(setting_screen_t *setting, sys_data_t *sys)
{
    float minX = 755;
    float maxX = 1070;
    float volume = (0.0);
    sfVector2i mousePos = sfMouse_getPositionRenderWindow(sys->window);

    if (!setting->isDragging)
        return;
    if (mousePos.x < minX)
        mousePos.x = minX;
    if (mousePos.x > maxX)
        mousePos.x = maxX;
    sfCircleShape_setPosition(setting->slider_cursor,
        (sfVector2f){mousePos.x - 5, 175});
    volume = ((mousePos.x - minX) / (maxX - minX)) * 100.0f;
    sfMusic_setVolume(sys->scene.musics.menu_music, volume);
    sfMusic_setVolume(sys->scene.musics.game_music, volume);
}
