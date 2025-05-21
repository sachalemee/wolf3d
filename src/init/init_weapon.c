/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** init_weapon.c
*/

#include "wolfengine.h"

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

static int init_icemaker_weapon(weapon_t *weapon)
{
    weapon->ttr_icemaker_rect = (sfIntRect){TTR_ICEMAKER_RECT_SIZE};
    weapon->ttr_icemaker = sfTexture_createFromFile(RES_ICEMAKER_WEAPON,
        NULL);
    if (weapon->ttr_icemaker == NULL)
        return FAILURE;
    return SUCCESS;
}

static int init_musics_weapon(weapon_t *weapon)
{
    weapon->main_weapon_shoot_sound = sfMusic_createFromFile(WATER_SONG_SHOOT);
    if (weapon->main_weapon_shoot_sound == NULL)
        return FAILURE;
    sfMusic_setVolume(weapon->main_weapon_shoot_sound, MAIN_SEC_VOL);
    weapon->leg_weapon_shoot_sound = sfMusic_createFromFile(FART_SONG_SHOOT);
    if (weapon->leg_weapon_shoot_sound == NULL)
        return FAILURE;
    sfMusic_setVolume(weapon->leg_weapon_shoot_sound, LEG_VOL);
    weapon->icemaker_weapon_shoot_sound =
        sfMusic_createFromFile(ICEMAKER_SONG_SHOOT);
    if (weapon->icemaker_weapon_shoot_sound == NULL)
        return FAILURE;
    sfMusic_setVolume(weapon->icemaker_weapon_shoot_sound, ICEMAKER_VOL);
    return EXIT_SUCCESS;
}

void destroy_weapon(weapon_t weapon)
{
    sfTexture_destroy(weapon.ttr_main);
    sfTexture_destroy(weapon.ttr_secondary);
    sfTexture_destroy(weapon.ttr_leg);
    sfTexture_destroy(weapon.ttr_icemaker);
    sfSprite_destroy(weapon.weapon_sprite);
    sfTexture_destroy(weapon.weapon_icon->ttr_main_icon);
    sfTexture_destroy(weapon.weapon_icon->ttr_secondary_icon);
    sfTexture_destroy(weapon.weapon_icon->ttr_leg_icon);
    sfTexture_destroy(weapon.weapon_icon->ttr_icemaker_icon);
    sfSprite_destroy(weapon.weapon_icon->weapon_icon_sprite);
    sfMusic_destroy(weapon.main_weapon_shoot_sound);
    sfMusic_destroy(weapon.leg_weapon_shoot_sound);
    sfMusic_destroy(weapon.icemaker_weapon_shoot_sound);
}

int init_each_weapon(weapon_t *weapon)
{
    if (init_main_weapon(weapon) == FAILURE)
        return FAILURE;
    if (init_secondary_weapon(weapon) == FAILURE)
        return FAILURE;
    if (init_leg_weapon(weapon) == FAILURE)
        return FAILURE;
    if (init_icemaker_weapon(weapon) == FAILURE)
        return FAILURE;
    return EXIT_SUCCESS;
}

int init_each_weapon_icon(weapon_icon_t *weapon_icon)
{
    if (init_main_weapon_icon(weapon_icon) == FAILURE)
        return FAILURE;
    if (init_secondary_weapon_icon(weapon_icon) == FAILURE)
        return FAILURE;
    if (init_leg_weapon_icon(weapon_icon) == FAILURE)
        return FAILURE;
    if (init_icemaker_weapon_icon(weapon_icon) == FAILURE)
        return FAILURE;
    return EXIT_SUCCESS;
}

int init_weapon(weapon_t *weapon)
{
    if (init_each_weapon(weapon) == FAILURE)
        return FAILURE;
    if (init_musics_weapon(weapon) == FAILURE)
        return FAILURE;
    weapon->weapon_icon = malloc(sizeof(weapon_icon_t));
    if (weapon->weapon_icon == NULL)
        return FAILURE;
    if (init_each_weapon_icon(weapon->weapon_icon) == FAILURE)
        return FAILURE;
    return SUCCESS;
}
