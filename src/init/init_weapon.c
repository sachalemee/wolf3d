/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** init_weapon.c
*/

#include "wolfengine.h"

void set_leg_weapon(weapon_t *weapon)
{
    sfVector2u ttr_leg_size = {0};

    sfSprite_setTexture(weapon->weapon_sprite, weapon->ttr_leg, sfFalse);
    ttr_leg_size = sfTexture_getSize(weapon->ttr_leg);
    sfSprite_setOrigin(weapon->weapon_sprite,
        (sfVector2f){ttr_leg_size.x / 6, ttr_leg_size.y});
    sfSprite_setScale(weapon->weapon_sprite, (sfVector2f){4, 4});
    sfSprite_setPosition(weapon->weapon_sprite,
        (sfVector2f){(WIN_WIDTH / 2) - WIN_LEG_POS,
        WIN_HEIGHT + WEAPON_POS_PADDING});
}

void set_secondary_weapon(weapon_t *weapon)
{
    sfVector2u ttr_secondary_size = {0};

    sfSprite_setTexture(weapon->weapon_sprite, weapon->ttr_secondary, sfFalse);
    ttr_secondary_size = sfTexture_getSize(weapon->ttr_secondary);
    sfSprite_setOrigin(weapon->weapon_sprite,
        (sfVector2f){ttr_secondary_size.x / 6, ttr_secondary_size.y});
    sfSprite_setScale(weapon->weapon_sprite, (sfVector2f){4, 4});
    sfSprite_setPosition(weapon->weapon_sprite,
        (sfVector2f){(WIN_WIDTH / 2) + WIN_WEAPON_POS,
        WIN_HEIGHT + WEAPON_POS_PADDING});
}

void set_primary_weapon(weapon_t *weapon)
{
    sfVector2u ttr_main_size = {0};

    sfSprite_setTexture(weapon->weapon_sprite, weapon->ttr_main, sfFalse);
    ttr_main_size = sfTexture_getSize(weapon->ttr_main);
    sfSprite_setOrigin(weapon->weapon_sprite,
        (sfVector2f){ttr_main_size.x / 6, ttr_main_size.y});
    sfSprite_setScale(weapon->weapon_sprite, (sfVector2f){4, 4});
    sfSprite_setPosition(weapon->weapon_sprite,
        (sfVector2f){(WIN_WIDTH / 2) + WIN_WEAPON_POS,
        WIN_HEIGHT + WEAPON_POS_PADDING});
}

static int init_main_weapon(weapon_t *weapon)
{
    weapon->ttr_main_rect = (sfIntRect){TTR_MAIN_RECT_SIZE};
    weapon->ttr_main = sfTexture_createFromFile(RES_MAIN_WEAPON, NULL);
    if (weapon->ttr_main == NULL)
        return FAILURE;
    weapon->weapon_sprite = sfSprite_create();
    set_primary_weapon(weapon);
    weapon->max_frame = MAIN_WEAPON_MAX_FRAME - 1;
    return SUCCESS;
}

static int init_secondary_weapon(weapon_t *weapon)
{
    weapon->ttr_secondary_rect = (sfIntRect){TTR_SECONDARY_RECT_SIZE};
    weapon->ttr_secondary = sfTexture_createFromFile(RES_SECONDARY_WEAPON,
        NULL);
    if (weapon->ttr_secondary == NULL)
        return FAILURE;
    return SUCCESS;
}

static int init_leg_weapon(weapon_t *weapon)
{
    weapon->ttr_leg_rect = (sfIntRect){TTR_SECONDARY_RECT_SIZE};
    weapon->ttr_leg = sfTexture_createFromFile(RES_LEG_WEAPON,
        NULL);
    if (weapon->ttr_leg == NULL)
        return FAILURE;
    return SUCCESS;
}

static int init_music_weapon(weapon_t *weapon)
{
    weapon->shooting_sound = sfMusic_createFromFile(SONG_SHOOT_GAME);
    if (weapon->shooting_sound == NULL)
        return FAILURE;
    return EXIT_SUCCESS;
}

void destroy_weapon(weapon_t weapon)
{
    sfTexture_destroy(weapon.ttr_main);
    sfTexture_destroy(weapon.ttr_secondary);
    sfTexture_destroy(weapon.ttr_leg);
    sfSprite_destroy(weapon.weapon_sprite);
    sfMusic_destroy(weapon.shooting_sound);
}

int init_weapon(weapon_t *weapon)
{
    if (init_main_weapon(weapon) == FAILURE)
        return FAILURE;
    if (init_secondary_weapon(weapon) == FAILURE)
        return FAILURE;
    if (init_leg_weapon(weapon) == FAILURE)
        return FAILURE;
    if (init_music_weapon(weapon) == FAILURE)
        return FAILURE;
    return SUCCESS;
}
