/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-marin.jeunot
** File description:
** init_setting
*/

#include "wolfengine.h"
#include "buttons.h"
#include <stdlib.h>
#include <stddef.h>

void destroy_setting_screen(setting_screen_t *setting)
{
        if (setting->setting_sprite != NULL)
            sfTexture_destroy(setting->setting_texture);
    free(setting);
}

int init_setting_screen(setting_screen_t *setting)
{
    (setting)->setting_texture = sfTexture_createFromFile(BG_SETTING, sfFalse);
    (setting)->setting_sprite = sfSprite_create();
    if ((setting)->setting_sprite == NULL
        || (setting)->setting_sprite == NULL) {
        destroy_setting_screen(setting);
        return FAILURE;
    }
    sfSprite_setTexture((setting)->setting_sprite,
        (setting)->setting_texture, sfTrue);
    return SUCCESS;
}
