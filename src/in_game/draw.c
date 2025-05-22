/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** draw.c
*/

#include "wolfengine.h"

void draw_face(sys_data_t *sys, player_t *player)
{
    if (player->health >= 90){
        sfRenderWindow_drawSprite(sys->window, player->face_sprite, NULL);
        sfSprite_setPosition(player->face_sprite, (sfVector2f){1700, 930});
        sfSprite_setScale(player->face_sprite, (sfVector2f){30, 30});
        sfSprite_setTextureRect(player->face_sprite, (sfIntRect){0, 0, 0, 0});
    }
    /* if (player->health >= 80) */
    /* if (player->health >= 60) */
    /* if (player->health >= 50) */
    /* if (player->health >= 1) */
}

void draw_bar(sys_data_t *sys, bar_t *bar)
{
    sfRenderWindow_drawRectangleShape(sys->window, bar->hp_bar, sfFalse);
    sfRenderWindow_drawRectangleShape(sys->window, bar->shield_bar, sfFalse);
}

void draw_in_game(sys_data_t *sys, game_t *game, map_t map)
{
    draw_background(sys->window, game->ground_sky->background_dsp_rect,
        sys->win_dimension);
    raycasting(game->player.camera, map, game->wall_sprites, sys->window);
    draw_hud(&(game->hud), sys->window);
    game->weapon.win_dimension = sys->win_dimension;
    draw_weapon(&(game->weapon), sys->window, &sys->time);
    draw_sprint_overlay(game, sys->window, &sys->time);
    draw_bar(sys, game->player.bar);
    //draw_face(sys, sys->scene.game.player);
}
