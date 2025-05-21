/*
** EPITECH PROJECT, 2025
** G-ING-200-PAR-2-1-myworld-sacha.lemee
** File description:
** init_buttons.c
*/

#include <stdlib.h>
#include "buttons.h"
#include "wolfengine.h"

void destroy_buttons(buttons_t **buttons)
{
    if (buttons != NULL) {
        free_button(buttons[0]);
        free_button(buttons[1]);
        free_button(buttons[2]);
    }
    free(buttons);
}

int init_buttons(buttons_t ***buttons)
{
    *buttons = calloc(NB_BUTTONS_MENU, sizeof(buttons_t *));
    if (buttons == NULL)
        return FAILURE;
    (*buttons)[0] = create_button((sfVector2f){1400, 330},
        (sfVector2f){350, 100}, " ", PLAY_BUTTON_PATH);
    (*buttons)[1] = create_button((sfVector2f){1400, 530},
        (sfVector2f){350, 100}, " ", SETTING_BUTTON_PATH);
    (*buttons)[2] = create_button((sfVector2f){1400, 730},
        (sfVector2f){350, 100}, " ", EXIT_BUTTON_PATH);
    if (!(*buttons)[0] || !(*buttons)[1] || !(*buttons)[2]) {
        destroy_buttons(*buttons);
        return FAILURE;
    }
    (*buttons)[0]->function = play_game;
    (*buttons)[1]->function = into_setting;
    (*buttons)[2]->function = close_menu;
    return SUCCESS;
}
