/*
** EPITECH PROJECT, 2025
** wolfengine
** File description:
** events_loop.c
*/

#include "wolfengine.h"

static void close_window(game_t *game, sfEvent event)
{
    if (is_keyboard_input(event, sfKeyEscape) || event.type == sfEvtClosed) {
        sfRenderWindow_close(game->window);
    }
}

sfBool is_keyboard_input(sfEvent event, sfKeyCode key)
{
    if (event.type == sfEvtKeyPressed && event.key.code == key)
        return sfTrue;
    return sfFalse;
}

static void mov_sprint(player_t *player, time_info_t info)
{
    if (sfKeyboard_isKeyPressed(sfKeyZ)
        && sfKeyboard_isKeyPressed(sfKeyLShift))
        player->mov->mov_speed =
        (info.delta_time * PLAYER_MOV_SPEED) * PLAYER_SPRINT_SPEED;
}

int events(game_t *game, player_t *player, time_info_t info, map_t map)
{
    sfEvent event;

    mov_sprint(player, info);
    mov_player(player, map);
    while (sfRenderWindow_pollEvent(game->window, &event)) {
        close_window(game, event);
    }
    return EXIT_S;
}
