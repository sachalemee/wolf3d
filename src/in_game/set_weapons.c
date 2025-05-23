/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** set_weapons.c
*/

#include "wolfengine.h"

void set_icemaker_weapon(weapon_t *weapon)
{
    sfVector2u ttr_icemaker = {0};

    sfSprite_setTexture(weapon->weapon_sprite, weapon->ttr_icemaker, sfTrue);
    ttr_icemaker = sfTexture_getSize(weapon->ttr_icemaker);
    sfSprite_setOrigin(weapon->weapon_sprite,
        (sfVector2f){ttr_icemaker.x / 6, ttr_icemaker.y});
    sfSprite_setScale(weapon->weapon_sprite, (sfVector2f){3, 3});
    sfSprite_setPosition(weapon->weapon_sprite,
        (sfVector2f){(WIN_WIDTH / 2) - 170,
        WIN_HEIGHT + WEAPON_POS_PADDING});
}

void set_leg_weapon(weapon_t *weapon)
{
    sfVector2u ttr_leg_size = {0};

    sfSprite_setTexture(weapon->weapon_sprite, weapon->ttr_leg, sfTrue);
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

    sfSprite_setTexture(weapon->weapon_sprite, weapon->ttr_secondary, sfTrue);
    ttr_secondary_size = sfTexture_getSize(weapon->ttr_secondary);
    sfSprite_setOrigin(weapon->weapon_sprite,
        (sfVector2f){ttr_secondary_size.x / 6, ttr_secondary_size.y});
    sfSprite_setScale(weapon->weapon_sprite, (sfVector2f){4, 4});
    sfSprite_setPosition(weapon->weapon_sprite,
        (sfVector2f){(WIN_WIDTH / 2) + WIN_SECONDARY_WEAPON_POS,
        WIN_HEIGHT + WEAPON_POS_PADDING});
}

void set_flashlight_weapon(weapon_t *weapon)
{
    sfVector2u ttr_flashlight_size = {0};

    sfSprite_setTexture(weapon->flashlight_sprite,
        weapon->ttr_flashlight, sfTrue);
    ttr_flashlight_size = sfTexture_getSize(weapon->ttr_flashlight);
    sfSprite_setOrigin(weapon->flashlight_sprite,
        (sfVector2f){ttr_flashlight_size.x / 6, ttr_flashlight_size.y});
    sfSprite_setScale(weapon->flashlight_sprite, (sfVector2f){0.5, 0.5});
    sfSprite_setPosition(weapon->flashlight_sprite,
        (sfVector2f){WIN_WIDTH + 9, WIN_HEIGHT - 50});
    sfSprite_setRotation(weapon->flashlight_sprite, -90);
}

void set_primary_weapon(weapon_t *weapon)
{
    sfVector2u ttr_main_size = {0};

    sfSprite_setTexture(weapon->weapon_sprite, weapon->ttr_main, sfTrue);
    ttr_main_size = sfTexture_getSize(weapon->ttr_main);
    sfSprite_setOrigin(weapon->weapon_sprite,
        (sfVector2f){ttr_main_size.x / 6, ttr_main_size.y});
    sfSprite_setScale(weapon->weapon_sprite, (sfVector2f){4, 4});
    sfSprite_setPosition(weapon->weapon_sprite,
        (sfVector2f){(WIN_WIDTH / 2) + WIN_MAIN_WEAPON_POS,
        WIN_HEIGHT + WEAPON_POS_PADDING});
}
