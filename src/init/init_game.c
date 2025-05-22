/*
** EPITECH PROJECT, 2025
** wolfengine
** File description:
** init_game.c
*/

#include "wolfengine.h"
#include "player.h"
#include <stdlib.h>

static int get_param_map(const char *_Nullable map_path,
    ssize_t *level, map_t **current_map)
{
    if (map_path == NULL) {
        *level = 0;
        *current_map = get_level((size_t)*level);
    } else {
        *level = -1;
        *current_map = get_map(map_path);
    }
    if (*current_map == NULL)
        return FAILURE;
    return SUCCESS;
}

static void destroy_sprites(sprites_t sprites)
{
    if (sprites.sprint_overlay_tex)
        sfTexture_destroy(sprites.sprint_overlay_tex);
    if (sprites.sprint_overlay)
        sfSprite_destroy(sprites.sprint_overlay);
}

static void destroy_bar(bar_t *bar)
{
    if (!bar)
        return;
    if (bar->hp_bar)
        sfRectangleShape_destroy(bar->hp_bar);
    if (bar->shield_bar)
        sfRectangleShape_destroy(bar->shield_bar);
}

void destroy_game(game_t game)
{
    destroy_wall_sprites(game.wall_sprites);
    destroy_map(game.current_map);
    destroy_player(game.player);
    sfRectangleShape_destroy(game.ground_sky->background_dsp_rect);
    destroy_sprites(game.sprites);
    destroy_bar(game.player.bar);
    free(game.raycast_data);
}

void free_ground_sky(ground_sky_t *ground_sky)
{
    if (!ground_sky)
        return;
    if (ground_sky->background_dsp_rect)
        sfRectangleShape_destroy(ground_sky->background_dsp_rect);
    free(ground_sky);
}

static int init_background_disp_rect(ground_sky_t **ground_sky)
{
    (*ground_sky) = malloc(sizeof(ground_sky_t));
    if ((*ground_sky) == NULL)
        return FAILURE;
    (*ground_sky)->background_dsp_rect = sfRectangleShape_create();
    if ((*ground_sky)->background_dsp_rect == NULL) {
        free_ground_sky((*ground_sky));
        return FAILURE;
    }
    (*ground_sky)->ground_sprite = sfSprite_create();
    sfRectangleShape_setSize((*ground_sky)->background_dsp_rect,
        (sfVector2f){WIN_WIDTH, WIN_HEIGHT / 2});
    return SUCCESS;
}

static int init_sprites(sprites_t *sprites)
{
    sfTexture *texture = sfTexture_createFromFile(TEXTURE_OVERLAY_SPRINT,
        NULL);
    sfSprite *sprite = sfSprite_create();

    if (texture == NULL || sprite == NULL) {
        destroy_sprites((sprites_t){texture, sprite, {0}});
        return FAILURE;
    }
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, (sfVector2f){-1000, -750});
    sfSprite_setColor(sprite, sfColor_fromRGBA(255, 255, 102, 75));
    sfSprite_setScale(sprite, (sfVector2f){2.5 * 2, 3 * 2});
    sprites->sprint_overlay_tex = texture;
    sprites->sprint_overlay = sprite;
    sprites->sprint_overlay_rect = (sfIntRect){
        TEXTURE_SPRINT_RECT_SIZE};
    return SUCCESS;
}

void set_bar(bar_t **bar, player_t *player)
{
    player->armor = MAX_SHIELD;
    player->health = MAX_HP;
    (*bar)->size_hp = (sfVector2f){SIZE_HP};
    (*bar)->size_shield = (sfVector2f){SIZE_SHIELD};
    sfRectangleShape_setSize((*bar)->hp_bar, (sfVector2f){SIZE_HP});
    sfRectangleShape_setSize((*bar)->shield_bar, (sfVector2f){SIZE_SHIELD});
    sfRectangleShape_setFillColor((*bar)->hp_bar, sfRed);
    sfRectangleShape_setFillColor((*bar)->shield_bar, sfCyan);
    sfRectangleShape_setPosition((*bar)->hp_bar, (sfVector2f){240, 916});
    sfRectangleShape_setPosition((*bar)->shield_bar, (sfVector2f){240, 1024});
}

static int init_bar(bar_t **bar, player_t *player)
{
    (*bar) = malloc(sizeof(bar_t));
    if ((*bar) == NULL)
        return FAILURE;
    (*bar)->hp_bar = sfRectangleShape_create();
    (*bar)->shield_bar = sfRectangleShape_create();
    if ((*bar)->hp_bar == NULL || (*bar)->shield_bar == NULL)
        return FAILURE;
    set_bar(bar, player);
    return SUCCESS;
}

int init_game(game_t *game, const char *_Nullable map_path,
    sfRenderWindow *win)
{
    sfVector2u win_size = sfRenderWindow_getSize(win);

    game->raycast_data = malloc(win_size.x * sizeof(float));
    if (game->raycast_data == NULL)
        return FAILURE;
    if (get_param_map(map_path, &(game->level), &(game->current_map))
            == FAILURE
        || init_wall_sprites(&(game->wall_sprites)) == FAILURE
        || init_player(game->current_map->start, &(game->player)) == FAILURE
        || init_background_disp_rect(&(game->ground_sky)) == FAILURE
        || init_sprites(&(game->sprites)) == FAILURE
        || init_weapon(&(game->weapon)) == FAILURE
        || init_hud(&(game->hud)) == FAILURE
        || init_bar(&(game->player.bar), &(game->player)) == FAILURE) {
        destroy_game(*game);
        return FAILURE;
    }
    return SUCCESS;
}
