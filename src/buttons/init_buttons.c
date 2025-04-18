/*
** EPITECH PROJECT, 2025
** G-ING-200-PAR-2-1-myworld-sacha.lemee
** File description:
** init_buttons.c
*/

#include <stdlib.h>
#include "buttons.h"
#include "wolfengine.h"

void init_buttons(game_t *game)
{
    game->buttons = malloc(sizeof(game->buttons) * NB_BUTTONS);
    game->buttons[0] = create_button((sfVector2f){100, 100},
        (sfVector2f){50, 50}, "test", B_TEXTURE);
}
