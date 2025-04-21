/*
** EPITECH PROJECT, 2025
** wolfengine
** File description:
** events_loop.c
*/

#include "wolfengine.h"
#include <stdio.h>

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

static void mov_sprint(player_t *player, info_t *info)
{
    if (sfKeyboard_isKeyPressed(sfKeyZ)
        && sfKeyboard_isKeyPressed(sfKeyLShift))
        player->mov->mov_speed =
        (info->d_time * PLAYER_MOV_SPEED) * PLAYER_SPRINT_SPEED;
}

int events(game_t *game, player_t *player, info_t *info)
{
    sfEvent event;

    mov_sprint(player, info);
    mov_player(player);
    while (sfRenderWindow_pollEvent(game->window, &event)) {
        if (is_keyboard_input(event, sfKeyF11)) {
            sfRenderWindow_destroy(game->window);
            game->window = set_window();
        }
        close_window(game, event);
    }
    return EXIT_S;
}
