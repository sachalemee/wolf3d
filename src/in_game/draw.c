/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** draw.c
*/

#include "wolfengine.h"

void set_face(player_t *player)
{
    if (player->health == 183)
        sfSprite_setTextureRect(player->face_sprite, player->rect_face);
    if (player->health == 170) {
        player->rect_face.left = 1 * 110;
        sfSprite_setTextureRect(player->face_sprite, player->rect_face);
    }
    if (player->health == 90) {
        player->rect_face.left = 2 * 110;
        sfSprite_setTextureRect(player->face_sprite, player->rect_face);
    }
    if (player->health == 45) {
        player->rect_face.left = 3 * 110;
        sfSprite_setTextureRect(player->face_sprite, player->rect_face);
    }
    if (player->health == 5) {
        player->rect_face.left = 4 * 110;
        sfSprite_setTextureRect(player->face_sprite, player->rect_face);
    }
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
    set_face(&(sys->scene.game.player));
    sfRenderWindow_drawSprite(sys->window,
        sys->scene.game.player.face_sprite, NULL);
}
