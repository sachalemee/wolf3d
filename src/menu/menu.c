/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-marin.jeunot
** File description:
** menu
*/

#include "wolfengine.h"
#include "buttons.h"
#include <stdio.h>

void play_game(game_t *game)
{
    game->state = STATE_GAME;
}

int menu(game_t *game, entity_t *entity)
{
    events_menu(game);

    if (game->state != STATE_MENU) {
        free_everything_button(game);
        return EXIT_S;
    }
    animated_bg(entity);
    draw_bg_menu(game, entity);
    return EXIT_S;
}
