/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** calls.c
*/

#include "wolfengine.h"

static void close_game(game_t *game, sfEvent event)
{
    if (is_keyboard_input(event, sfKeyEscape) || event.type == sfEvtClosed) {
        sfRenderWindow_close(game->window);
    }
}

static void mov_sprint(player_t *player, info_t *info)
{
    if (sfKeyboard_isKeyPressed(sfKeyZ)
        && sfKeyboard_isKeyPressed(sfKeyLShift))
        player->mov->mov_speed =
        (info->d_time * PLAYER_MOV_SPEED) * PLAYER_SPRINT_SPEED;
}

int events_game(game_t *game, player_t *player, info_t *info)
{
    sfEvent event;

    mov_sprint(player, info);
    mov_player(player);
    while (sfRenderWindow_pollEvent(game->window, &event)) {
        close_game(game, event);
    }
    return EXIT_S;
}
