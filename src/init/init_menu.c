/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-marin.jeunot
** File description:
** init_menu
*/

#include "wolfengine.h"
#include "buttons.h"
#include <stdlib.h>
#include <stddef.h>

void destroy_menu(menu_t menu)
{
    destroy_entity(menu.entity);
    destroy_buttons(menu.buttons);
    sfTexture_destroy(menu.panel_text);
}

crosshair_t *init_crosshair(void)
{
    crosshair_t *crosshair = malloc(sizeof(crosshair_t));

    if (crosshair == NULL)
        return NULL;
    crosshair->ttr = sfTexture_createFromFile("ressources/Wolf3D_OGG/texture/"
        "shell_crosshair.png", NULL);
    crosshair->spr = sfSprite_create();
    crosshair->pos = (sfVector2f){0};
    crosshair->scale = (sfVector2f){0};
    return crosshair;
}

custom_settings_t *init_custom_settings(void)
{
    custom_settings_t *custom_setting = malloc(sizeof(custom_settings_t));

    if (custom_setting == NULL)
        return NULL;
    custom_setting->crosshair = init_crosshair();
    return custom_setting;
}

int init_panel(menu_t *menu)
{
    (menu)->panel_text =
        sfTexture_createFromFile(PANEL_BUTTON_TEXTURE, sfFalse);
    (menu)->panel_sprite = sfSprite_create();
    if ((menu)->panel_sprite == NULL
        || (menu)->panel_text == NULL) {
        return FAILURE;
    }
    sfSprite_setTexture((menu)->panel_sprite,
        (menu)->panel_text, sfTrue);
    sfSprite_setScale(menu->panel_sprite, (sfVector2f){PANEL_SCALE});
    sfSprite_setPosition(menu->panel_sprite, (sfVector2f){POS_PANEL});
    return SUCCESS;
}

int init_menu(menu_t *menu)
{
    if (init_buttons(&(menu->buttons)) == FAILURE
        || init_entity(&(menu->entity)) == FAILURE
        || init_panel(menu) == FAILURE) {
        destroy_menu(*menu);
        return FAILURE;
    }
    return SUCCESS;
}
