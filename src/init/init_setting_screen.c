/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-marin.jeunot
** File description:
** init_setting
*/

#include <stdlib.h>
#include <stddef.h>
#include "wolfengine.h"
#include "buttons.h"

void destroy_setting_screen(setting_screen_t *setting)
{
    if (setting->setting_sprite != NULL)
        sfTexture_destroy(setting->setting_texture);
    if (setting->slider_cursor != NULL)
        sfCircleShape_destroy(setting->slider_cursor);
    if (setting->slider_texture != NULL)
        sfTexture_destroy(setting->slider_texture);
}

void destroy_buttons_setting(buttons_t **buttons)
{
    if (buttons != NULL) {
        free_button(buttons[0]);
        free_button(buttons[1]);
        free_button(buttons[2]);
        free_button(buttons[3]);
    }
    free(buttons);
}

static int init_slider(setting_screen_t *setting)
{
    setting->slider_texture = sfTexture_createFromFile(CURSOR_SETTING, NULL);
    if (!setting->slider_texture)
        return FAILURE;
    setting->slider_cursor = sfCircleShape_create();
    sfCircleShape_setRadius(setting->slider_cursor, 30);
    sfCircleShape_setTexture(setting->slider_cursor,
        setting->slider_texture, sfTrue);
    sfCircleShape_setPosition(setting->slider_cursor, (sfVector2f){755, 175});
    setting->isDragging = 0;
    return SUCCESS;
}

static int init_buttons_settings(buttons_t ***buttons)
{
    *buttons = calloc(NB_BUTTONS_SETTINGS, sizeof(buttons_t *));
    if (buttons == NULL)
        return FAILURE;
    (*buttons)[0] = create_button((sfVector2f){760, 160},
        (sfVector2f){350, 100}, " ", SOUND_BUTTON);
    (*buttons)[1] = create_button((sfVector2f){760, 360},
        (sfVector2f){350, 100}, " ", FOV_BUTTON);
    (*buttons)[2] = create_button((sfVector2f){760, 560},
        (sfVector2f){350, 100}, " ", DFTY_BUTTON);
    (*buttons)[3] = create_button((sfVector2f){760, 760},
        (sfVector2f){350, 100}, " ", TO_MENU_BUTTON);
    if (!(*buttons)[0] || !(*buttons)[1] || !(*buttons)[2] || !(*buttons[3]))
        destroy_buttons_setting(*buttons);
    (*buttons)[0]->function = unused_button;
    (*buttons)[1]->function = unused_button;
    (*buttons)[2]->function = unused_button;
    (*buttons)[3]->function = return_to_menu;
    return SUCCESS;
}

static int init_texture_setting(setting_screen_t *setting)
{
    (setting)->setting_sprite = sfSprite_create();
    (setting)->setting_texture = sfTexture_createFromFile(BG_SETTING, sfFalse);
    if ((setting)->setting_sprite == NULL
        || (setting)->setting_texture == NULL)
            return FAILURE;
    sfSprite_setTexture((setting)->setting_sprite,
        (setting)->setting_texture, sfTrue);
    return SUCCESS;
}

void destroy_settings(setting_screen_t setting)
{
    destroy_buttons_setting(setting.buttons);
    destroy_setting_screen(&(setting));
}

int init_setting_screen(setting_screen_t *setting)
{
    if (init_texture_setting(setting) == FAILURE
    || init_buttons_settings(&(setting->buttons)) == FAILURE
    || init_slider(setting) == FAILURE) {
        destroy_settings(*setting);
        return FAILURE;
    }
    return SUCCESS;
}
