/*
** EPITECH PROJECT, 2025
** wolfengine
** File description:
** init_player.c
*/

#include <stdlib.h>
#include "wolfengine.h"

void destroy_player(player_t player)
{
    free(player.mov);
    free(player.camera.render_dist);
    free(player.sound);
    sfTexture_destroy(player.face_texure);
    sfSprite_destroy(player.face_sprite);
}

static player_sound_t *init_player_sound(void)
{
    player_sound_t *player_sound = malloc(sizeof(player_sound_t));

    if (player_sound == NULL)
        return NULL;
    player_sound->sound_footstep = sfMusic_createFromFile(MUSIC_PATH_FOOTSTEP);
    return player_sound;
}

int init_face(player_t *player)
{
    player->face_sprite = sfSprite_create();
    player->face_texure = sfTexture_createFromFile(FACE_PATH, sfFalse);
    if (player->face_sprite == NULL || player->face_texure == NULL)
        return FAILURE;
    sfSprite_setTexture(player->face_sprite,
        player->face_texure, sfTrue);
    sfSprite_setScale(player->face_sprite, (sfVector2f){FACE_SCALE});
    sfSprite_setPosition(player->face_sprite, (sfVector2f){FACE_POS});
    player->rect_face = (sfIntRect){INTRECT_FACE};
    return SUCCESS;
}

int init_player(sfVector2f coords, player_t *dest)
{
    if (init_face(dest) == FAILURE)
        destroy_player(*dest);
    dest->health = MAX_HP;
    dest->armor = MAX_SHIELD;
    dest->mov = calloc(1, sizeof(player_settings_t));
    dest->camera.render_dist = calloc(1, sizeof(size_t));
    if (check_mallocs(2, "", dest->camera.render_dist, dest->mov) == false)
        return FAILURE;
    dest->camera.dir = (sfVector2f){-1, 0.0};
    dest->camera.plane = (sfVector2f){0.0, PLAYER_FOV};
    dest->camera.pos = (sfVector2f){coords.x + 0.5, (int)coords.y + 0.5};
    *(dest->camera.render_dist) = DEFAULT_RENDER_DIST;
    dest->map = (sfVector2i){(int)coords.x, (int)coords.y};
    dest->mov->render_dist = dest->camera.render_dist;
    dest->sound = init_player_sound();
    return SUCCESS;
}
