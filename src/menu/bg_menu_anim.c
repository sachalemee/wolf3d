/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-marin.jeunot
** File description:
** bg_menu_anim
*/

#include "wolfengine.h"
#include "buttons.h"

void draw_bg_menu(menu_t *menu, sfRenderWindow *win)
{
    sfRenderWindow_clear(win, sfBlack);
    sfSprite_setScale(menu->entity->sprite.sprite_bg,
        (sfVector2f){MENU_SCALE});
    sfRenderWindow_drawSprite(win, menu->entity->sprite.sprite_bg, NULL);
    draw_all_buttons(menu, win);
    sfRenderWindow_display(win);
}

void animated_bg(entity_t *entity, time_info_t *time)
{
    if (time->delta_time > 0.2) {
        entity->anim.current_frame = (entity->anim.current_frame + 1)
            % entity->anim.max_frame;
        entity->anim.rect.left = entity->anim.current_frame * BG_RECT;
        sfSprite_setTextureRect(entity->sprite.sprite_bg,
            entity->anim.rect);
    }
}
