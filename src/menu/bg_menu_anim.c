/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-marin.jeunot
** File description:
** bg_menu_anim
*/

#include "wolfengine.h"
#include "buttons.h"

void animated_bg(entity_t *entity, time_info_t *time)
{
    time->last_update = (int)(time->last_update * BG_SPEED_FRAME)
        % entity->anim.max_frame;
    entity->anim.rect.left = time->last_update * BG_RECT;
    sfSprite_setTextureRect(entity->sprite.sprite_bg, entity->anim.rect);
}

void draw_bg_menu(menu_t *menu, sfRenderWindow *win)
{
    sfSprite_setScale(menu->entity->sprite.sprite_bg,
        (sfVector2f){MENU_SCALE});
    sfRenderWindow_drawSprite(win, menu->entity->sprite.sprite_bg, NULL);
    sfRenderWindow_drawSprite(win, menu->panel_sprite, NULL);
    draw_menu_buttons(menu, win);
}
