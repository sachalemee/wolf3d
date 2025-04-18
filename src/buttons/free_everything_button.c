/*
** EPITECH PROJECT, 2025
** G-ING-200-PAR-2-1-myworld-sacha.lemee
** File description:
** free_everything_button.c
*/

#include "buttons.h"
#include "wolfengine.h"
#include <stdlib.h>

static void free_button(buttons_t *buttons)
{
    sfRectangleShape_destroy(buttons->rect);
    if (buttons->sprite != NULL)
        sfSprite_destroy(buttons->sprite);
    if (buttons->texture != NULL)
        sfTexture_destroy(buttons->texture);
    if (buttons->title != NULL)
        sfText_destroy(buttons->title);
    free(buttons);
}

void free_everything_button(game_t *game)
{
    free_button(game->buttons[0]);
    free_button(game->buttons[1]);
    free_button(game->buttons[2]);
    free(game->buttons);
}
