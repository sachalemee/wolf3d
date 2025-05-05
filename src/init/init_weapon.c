/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** init_weapon.c
*/

#include "wolfengine.h"

static int init_main_weapon(weapon_t *weapon)
{
    sfVector2u ttr_main_size = {0};

    weapon->ttr_main_rect = (sfIntRect){TTR_MAIN_RECT_SIZE};
    weapon->ttr_main = sfTexture_createFromFile(RES_MAIN_WEAPON, NULL);
    if (weapon->ttr_main == NULL)
        return FAILURE;
    weapon->spr_main = sfSprite_create();
    sfSprite_setTexture(weapon->spr_main, weapon->ttr_main, sfFalse);
    ttr_main_size = sfTexture_getSize(weapon->ttr_main);
    sfSprite_setOrigin(weapon->spr_main,
        (sfVector2f){ttr_main_size.x / 6, ttr_main_size.y});
    sfSprite_setScale(weapon->spr_main, (sfVector2f){4, 4});
    sfSprite_setPosition(weapon->spr_main,
        (sfVector2f){(WIN_WIDTH / 2) + WIN_WEAPON_POS,
        WIN_HEIGHT + WEAPON_POS_PADDING});
    return SUCCESS;
}

void destroy_weapon(weapon_t weapon)
{
    sfTexture_destroy(weapon.ttr_main);
    sfSprite_destroy(weapon.spr_main);
}

int init_weapon(weapon_t *weapon)
{
    if (init_main_weapon(weapon) == FAILURE)
        return FAILURE;
    return SUCCESS;
}
