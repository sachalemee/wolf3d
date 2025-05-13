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

void destroy_settings(setting_screen_t setting)
{
    destroy_buttons_setting(setting.buttons);
    destroy_setting_screen(&(setting));
}

void destroy_setting_screen(setting_screen_t *setting)
{
    if (setting->setting_sprite != NULL)
        sfTexture_destroy(setting->setting_texture);
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

static int init_buttons_settings(buttons_t ***buttons)
{
    *buttons = calloc(NB_BUTTONS_SETTINGS, sizeof(buttons_t *));
    if (buttons == NULL)
        return FAILURE;
    (*buttons)[0] = create_button((sfVector2f){960, 540},
        (sfVector2f){350, 100}, "SOUND", SOUND_BUTTON_PATH);
    (*buttons)[1] = create_button((sfVector2f){960, 640},
        (sfVector2f){350, 100}, "DIFICULTY", NULL);
    (*buttons)[2] = create_button((sfVector2f){960, 740},
        (sfVector2f){350, 100}, "FOV", NULL);
    (*buttons)[3] = create_button((sfVector2f){960, 840},
        (sfVector2f){350, 100}, "RETURN TO MENU", NULL);
    if (!(*buttons)[0] || !(*buttons)[1] || !(*buttons)[2] || !(*buttons[3]))
        destroy_buttons_setting(*buttons);
    return EXIT_SUCCESS;
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
    if (init_buttons_settings(&(setting->buttons)) == FAILURE)
        return FAILURE;
    sfSprite_setTexture((setting)->setting_sprite,
        (setting)->setting_texture, sfTrue);
    return SUCCESS;
}
