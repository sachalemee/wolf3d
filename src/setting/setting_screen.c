/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-marin.jeunot
** File description:
** setting_screen
*/

#include "wolfengine.h"
#include "buttons.h"
#include "my.h"
#include <stdio.h>

void into_setting(sys_data_t *sys)
{
    sys->scene.state = STATE_SETTING;
}

void draw_setting(setting_screen_t *setting, sfRenderWindow *win)
{
    sfRenderWindow_drawSprite(win, setting->setting_sprite, NULL);
    draw_setting_buttons(setting, win);
    sfRenderWindow_drawCircleShape(win, setting->slider_cursor, NULL);
}

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

int update_setting(game_t *game, sys_data_t *sys)
{
    UNUSED(game);
    sfRenderWindow_clear(sys->window, sfWhite);
    events_setting(sys);
    update_slider(&(sys->scene.setting_screen), sys);
    draw_setting(&(sys->scene.setting_screen), sys->window);
    sfRenderWindow_display(sys->window);
    return EXIT_S;
}
