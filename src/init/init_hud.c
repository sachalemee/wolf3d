/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-marin.jeunot
** File description:
** init_hud
*/

#include "wolfengine.h"

int init_hud(hud_t *hud)
{
    hud->hud_texture = sfTexture_createFromFile(HUD_PATH, sfFalse);
    hud->hud_sprite = sfSprite_create();
    if (hud->hud_texture == NULL || hud->hud_sprite == NULL){
        free(hud);
        return 84;
    }
    sfSprite_setTexture(hud->hud_sprite, hud->hud_texture, sfTrue);
    return SUCCESS;
}
