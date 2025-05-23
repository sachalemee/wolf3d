/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** draw.c
*/

#include "wolfengine.h"

void set_face(player_t *player)
{
    if (player->health == MAX_HP)
        sfSprite_setTextureRect(player->face_sprite, player->rect_face);
    if (player->health == MAX_HP - SET_LIFE_MEASURE) {
        player->rect_face.left = FIRST_FRAME * RECT_FACE_LEFT;
        sfSprite_setTextureRect(player->face_sprite, player->rect_face);
    }
    if (player->health == MAX_HP - SET_LIFE_MEASURE * SECOND_FRAME) {
        player->rect_face.left = SECOND_FRAME * RECT_FACE_LEFT;
        sfSprite_setTextureRect(player->face_sprite, player->rect_face);
    }
    if (player->health == MAX_HP - SET_LIFE_MEASURE * THIRD_FRAME) {
        player->rect_face.left = THIRD_FRAME * RECT_FACE_LEFT;
        sfSprite_setTextureRect(player->face_sprite, player->rect_face);
    }
    if (player->health == MAX_HP - SET_LIFE_MEASURE * FOURTH_FRAME
        + CRITIC_HEALTH) {
        player->rect_face.left = FOURTH_FRAME * RECT_FACE_LEFT;
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
