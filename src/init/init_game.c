/*
** EPITECH PROJECT, 2025
** wolfengine
** File description:
** init_game.c
*/

#include "wolfengine.h"
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

void destroy_game(game_t game)
{
    destroy_wall_sprites(game.wall_sprites);
    destroy_map(game.current_map);
    destroy_player(game.player);
    sfRectangleShape_destroy(game.background_dsp_rect);
    destroy_sprites(game.sprites);
    free(game.raycast_data);
}

int init_background_disp_rect(sfRectangleShape **background_disp_rect)
{
    *background_disp_rect = sfRectangleShape_create();
    if (*background_disp_rect == NULL)
        return FAILURE;
    sfRectangleShape_setSize(
        *background_disp_rect, (sfVector2f){WIN_WIDTH, WIN_HEIGHT / 2});
    return SUCCESS;
}

int init_sprites(sprites_t *sprites)
{
    sfTexture *texture = sfTexture_createFromFile(TEXTURE_OVERLAY_SPRINT,
        NULL);
    sfSprite *sprite = sfSprite_create();

    if (texture == NULL || sprite == NULL) {
        destroy_sprites((sprites_t){texture, sprite});
        return FAILURE;
    }
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setColor(sprite, sfColor_fromRGBA(100, 240, 220, 75));
    sfSprite_setScale(sprite, (sfVector2f){3, 3});
    sprites->sprint_overlay_tex = texture;
    sprites->sprint_overlay = sprite;
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
        || init_background_disp_rect(&(game->background_dsp_rect)) == FAILURE
        || init_sprites(&(game->sprites)) == FAILURE) {
        destroy_game(*game);
        return FAILURE;
    }
    return SUCCESS;
}
