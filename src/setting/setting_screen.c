/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-marin.jeunot
** File description:
** setting_screen
*/

#include "wolfengine.h"
#include "buttons.h"
#include "my.h"

void into_setting(sys_data_t *sys)
{
    sfMusic_pause(sys->scene.musics.game_music);
    sfMusic_play(sys->scene.musics.menu_music);
    sys->scene.state = STATE_SETTING;
}

void draw_bg_setting(menu_t *menu, sfRenderWindow *win)
{
    sfSprite_setScale(menu->entity->sprite.sprite_bg,
        (sfVector2f){MENU_SCALE});
    sfRenderWindow_drawSprite(win, menu->entity->sprite.sprite_bg, NULL);
    draw_all_buttons(menu, win);
}

int update_setting(game_t *game, sys_data_t *sys)
{
    UNUSED(game);
    events_menu(sys);
    sfRenderWindow_clear(sys->window, sfWhite);
    draw_bg_setting(&(sys->scene.menu), sys->window);
    sfRenderWindow_display(sys->window);
    return EXIT_S;
}
