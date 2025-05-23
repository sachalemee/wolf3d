/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** init_weapon.c
*/

#include "wolfengine.h"

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

static void destroy_weapon_rsc(weapon_t weapon)
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
    sfTexture_destroy(weapon.weapon_ammo->ttr_main_ammo);
    sfTexture_destroy(weapon.weapon_ammo->ttr_secondary_ammo);
    sfTexture_destroy(weapon.weapon_ammo->ttr_leg_ammo);
    sfTexture_destroy(weapon.weapon_ammo->ttr_icemaker_ammo);
    sfSprite_destroy(weapon.weapon_ammo->weapon_ammo_sprite);
}

void destroy_weapon(weapon_t weapon)
{
    destroy_weapon_rsc(weapon);
    sfTexture_destroy(weapon.weapon_crosshair->ttr_main_crosshair);
    sfTexture_destroy(weapon.weapon_crosshair->ttr_secondary_crosshair);
    sfTexture_destroy(weapon.weapon_crosshair->ttr_leg_crosshair);
    sfTexture_destroy(weapon.weapon_crosshair->ttr_icemaker_crosshair);
    sfSprite_destroy(weapon.weapon_crosshair->weapon_crosshair_sprite);
    sfTexture_destroy(weapon.ttr_flashlight);
    sfSprite_destroy(weapon.flashlight_sprite);
    sfMusic_destroy(weapon.main_weapon_shoot_sound);
    sfMusic_destroy(weapon.leg_weapon_shoot_sound);
    sfMusic_destroy(weapon.icemaker_weapon_shoot_sound);
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
    weapon->weapon_ammo = malloc(sizeof(weapon_ammo_t));
    if (weapon->weapon_ammo == NULL)
        return FAILURE;
    if (init_each_weapon_ammo(weapon->weapon_ammo) == FAILURE)
        return FAILURE;
    weapon->weapon_crosshair = malloc(sizeof(weapon_crosshair_t));
    if (weapon->weapon_crosshair == NULL)
        return FAILURE;
    if (init_each_weapon_crosshair(weapon->weapon_crosshair) == FAILURE)
        return FAILURE;
    return SUCCESS;
}
