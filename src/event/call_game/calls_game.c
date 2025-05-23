/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** calls.c
*/

#include "wolfengine.h"

static void enter_next_level(game_t *game, sfEvent *event, bool *is_running)
{
    sfVector2f player_pos = game->player.camera.pos;
    sfVector2f end_pos = game->current_map->end;
    float approx_dist_end = ABS(player_pos.x - end_pos.x)
        + ABS(player_pos.y - end_pos.y);

    if (is_keyboard_input(event, sfKeyReturn) && approx_dist_end <= END_SIZE) {
        if (levels[game->level + 1] == NULL)
            return;
        (game->level)++;
        destroy_map(game->current_map);
        game->current_map = get_level(game->level);
        if (game->current_map == NULL)
            *is_running = sfFalse;
        game->player.camera.pos = game->current_map->start;
    }
}

void close_window(sys_data_t *sys, sfEvent *event)
{
    if (is_keyboard_input(event, sfKeyEscape) || event->type == sfEvtClosed)
        sys->is_running = sfFalse;
}

static void mov_sprint(player_t *player, time_info_t *info)
{
    if (sfKeyboard_isKeyPressed(sfKeyZ)
        && sfKeyboard_isKeyPressed(sfKeyLShift))
        player->mov->mov_speed =
        (info->delta_time * PLAYER_MOV_SPEED) * PLAYER_SPRINT_SPEED;
}

static bool player_is_out_of_map(player_t *player, map_t *map)
{
    return (
        player->camera.pos.x < 0 ||
        player->camera.pos.y < 0 ||
        player->camera.pos.x >= map->size.x ||
        player->camera.pos.y >= map->size.y
    );
}

int game_events(sys_data_t *sys)
{
    sfEvent event;
    game_t *game = &(sys->scene.game);
    player_t *player = &(sys->scene.game.player);
    time_info_t *info = &(sys->time);
    map_t *map = sys->scene.game.current_map;

    mov_sprint(player, info);
    mov_player(player, map);
    if (player_is_out_of_map(player, map))
        player->camera.pos = (sfVector2f){map->start.x + 0.5,
            map->start.y + 0.5};
    while (sfRenderWindow_pollEvent(sys->window, &event)) {
        close_window(sys, &event);
        if (set_fullscreen(sys, &event) == EXIT_F)
            return EXIT_F;
        enter_next_level(game, &event, &(sys->is_running));
    }
    return EXIT_S;
}
