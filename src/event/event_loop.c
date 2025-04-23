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

static void enter_next_level(sys_data_t *sys, sfEvent event)
{
    sfVector2f player_pos = sys->player->pos;
    sfVector2f end_pos = sys->current_map->end;
    float approx_dist_end = ABS(player_pos.x - end_pos.x)
        + ABS(player_pos.y - end_pos.y);

    if (is_keyboard_input(event, sfKeyReturn) && approx_dist_end <= END_SIZE) {
        if (levels[sys->level + 1] == NULL)
            return;
        (sys->level)++;
        destroy_map(sys->current_map);
        sys->current_map = get_level(sys->level);
        if (sys->current_map == NULL)
            sfRenderWindow_close(sys->game->window);
        sys->player->pos = sys->current_map->start;
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

int events(sys_data_t *sys)
{
    sfEvent event;
    game_t *game = sys->game;
    player_t *player = sys->player;
    time_info_t info = sys->game->time;
    map_t map = *(sys->current_map);

    mov_sprint(player, info);
    mov_player(player, map);
    while (sfRenderWindow_pollEvent(game->window, &event)) {
        close_window(game, event);
        enter_next_level(sys, event);
    }
    return EXIT_S;
}
