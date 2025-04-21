/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-marin.jeunot
** File description:
** bg_menu_anim
*/

#include "wolfengine.h"
#include "buttons.h"

void draw_bg_menu(game_t *game, entity_t *entity)
{
    sfRenderWindow_clear(game->window, sfBlack);
    sfSprite_setScale(entity->sprite->sprite_bg, (sfVector2f){1.25, 1.05});
    sfRenderWindow_drawSprite(game->window, entity->sprite->sprite_bg, NULL);
    draw_all_buttons(game->window, game);
    sfRenderWindow_display(game->window);
}

void animated_bg(entity_t *entity)
{
    float elapsed_time = sfTime_asSeconds(
        sfClock_getElapsedTime(entity->anim->clock_anim));

    if (elapsed_time > 0.2) {
        entity->anim->current_frame = (entity->anim->current_frame + 1)
            % entity->anim->max_frame;
        entity->anim->rect.left = entity->anim->current_frame * BG_RECT;
        sfSprite_setTextureRect(entity->sprite->sprite_bg,
            entity->anim->rect);
        sfClock_restart(entity->anim->clock_anim);
    }
}
