/*
** EPITECH PROJECT, 2025
** wolfengine
** File description:
** init_game.c
*/

#include "wolfengine.h"
#include <stdlib.h>

void destroy_horiz_surfaces(horiz_surfaces_t horizontal_surfaces)
{
    if (horizontal_surfaces.roof)
        sfRectangleShape_destroy(horizontal_surfaces.roof);
    if (horizontal_surfaces.floor)
        sfRectangleShape_destroy(horizontal_surfaces.floor);
}

void destroy_game(game_t *game)
{
    if (game) {
        destroy_horiz_surfaces(game->background);
        if (game->window)
            sfRenderWindow_destroy(game->window);
        if (game->time.clock)
            sfClock_destroy(game->time.clock);
        if (game->music)
            sfMusic_destroy(game->music);
        free(game);
    }
}

horiz_surfaces_t init_horiz_surfaces(void)
{
    sfColor color = sfColor_fromRGB(ROOF_RGB);
    horiz_surfaces_t new_horiz_surfaces = {0};
    new_horiz_surfaces.roof = sfRectangleShape_create();
    new_horiz_surfaces.floor = sfRectangleShape_create();

    if (!new_horiz_surfaces.roof || !new_horiz_surfaces.floor) {
        destroy_horiz_surfaces(new_horiz_surfaces);
        return (horiz_surfaces_t){0};
    }
    sfRectangleShape_setFillColor(new_horiz_surfaces.roof, color);
    sfRectangleShape_setSize(
        new_horiz_surfaces.roof, (sfVector2f){WIN_WIDTH, WIN_HEIGHT / 2});
    color = sfColor_fromRGB(FLOOR_RGB);
    sfRectangleShape_setFillColor(new_horiz_surfaces.floor, color);
    sfRectangleShape_setSize(
        new_horiz_surfaces.floor, (sfVector2f){WIN_WIDTH, WIN_HEIGHT / 2});
    sfRectangleShape_setPosition(
        new_horiz_surfaces.floor, (sfVector2f){0, WIN_HEIGHT / 2});
    return new_horiz_surfaces;
}

sprites_t init_textures(void)
{
    sfTexture *texture = sfTexture_createFromFile(TEXTURE_OVERLAY_SPRINT, NULL);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setColor(sprite, sfColor_fromRGBA(100, 240, 220, 75));
    sfSprite_setScale(sprite, (sfVector2f){3, 3});
    return (sprites_t){texture, sprite};
}

game_t *init_game(void)
{
    game_t *game = calloc(1, sizeof(game_t));

    if (game == NULL)
        return NULL;
    game->textures = init_textures();
    game->window = set_window();
    game->time.clock = sfClock_create();
    game->music = sfMusic_createFromFile(MUSIC_PATH);
    game->background = init_horiz_surfaces();
    if (!game->window || !game->background.floor || !game->music
        || !game->time.clock || !game->textures.sprint_overlay) {
        destroy_game(game);
        return NULL;
    }
    return game;
}
