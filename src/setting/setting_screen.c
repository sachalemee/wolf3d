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

void draw_bg_setting(setting_screen_t *setting, sfRenderWindow *win)
{
    //sfSprite_setScale(setting->setting_sprite, (sfVector2f){5.5, 5.5});
    sfRenderWindow_drawSprite(win, setting->setting_sprite, NULL);
    draw_setting_buttons(setting, win);
}

int update_setting(game_t *game, sys_data_t *sys)
{
    UNUSED(game);
    sfRenderWindow_clear(sys->window, sfWhite);
    events_setting(sys);
    draw_bg_setting(&(sys->scene.setting_screen), sys->window);
    sfRenderWindow_display(sys->window);
    return EXIT_S;
}
