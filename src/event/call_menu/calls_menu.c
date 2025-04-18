/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** calls.c
*/

#include "wolfengine.h"
#include "buttons.h"
#include <stdio.h>

static void close_menu(game_t *game)
{
    sfRenderWindow_close(game->window);
}

static void buttons_event(game_t *game, sfEvent event)
{
    game->buttons[0]->function = play_game;
    game->buttons[1]->function = play_game;
    game->buttons[2]->function = close_menu;
    for (int i = 0; i < NB_BUTTONS; i++)
        buttons_status(game->window, game->buttons[i], event, game);
}

int events_menu(game_t *game)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(game->window, &event)) {
        buttons_event(game, event);
    }
    return EXIT_S;
}
