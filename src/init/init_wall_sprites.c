/*
** EPITECH PROJECT, 2025
** wolfengine
** File description:
** init_game.c
*/

#include "wolfengine.h"
#include <stdlib.h>

static void destroy_single_wall_sprite(sfSprite *wall_sprite)
{
    const sfTexture *wall_texture = (wall_sprite == NULL) ? NULL
        : sfSprite_getTexture(wall_sprite);

    if (wall_sprite == NULL)
        return;
    sfTexture_destroy((void *)wall_texture);
    sfSprite_destroy((void *)wall_sprite);
}

void destroy_wall_sprites(sfSprite **wall_sprites)
{
    if (wall_sprites == NULL)
        return;
    for (size_t i = 0; wall_sprites[i] != NULL; i++)
        destroy_single_wall_sprite(wall_sprites[i]);
    free(wall_sprites);
}

static int init_single_wall_sprite(sfSprite **wall_sprite,
    const char *texture_name)
{
    sfTexture *current_texture = NULL;
    char *texture_path = NULL;

    texture_path = CONCAT(WALL_TEXTURES_PATH, texture_name);
    if (texture_path == NULL)
        return FAILURE;
    *wall_sprite = sfSprite_create();
    if (*wall_sprite != NULL)
        current_texture = sfTexture_createFromFile(texture_path, NULL);
    free(texture_path);
    if (*wall_sprite == NULL || current_texture == NULL)
        return FAILURE;
    sfSprite_setTexture(*wall_sprite, current_texture, sfTrue);
    return SUCCESS;
}

int init_wall_sprites(sfSprite ***wall_sprites)
{
    size_t count_wall_types = 0;

    for (; wall_textures[count_wall_types] != NULL; ++count_wall_types);
    *wall_sprites = calloc(count_wall_types + 1, sizeof(sfSprite *));
    if (*wall_sprites == NULL)
        return FAILURE;
    for (size_t i = 0; i < count_wall_types; i++) {
        if (init_single_wall_sprite(&((*wall_sprites)[i]), wall_textures[i])
            == FAILURE) {
            destroy_wall_sprites(*wall_sprites);
            return FAILURE;
        }
    }
    return SUCCESS;
}
