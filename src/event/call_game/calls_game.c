/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** calls.c
*/

#include "wolfengine.h"

static void enter_next_level(game_t *game, sfEvent event, bool *is_running)
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

void close_window(sys_data_t *sys, sfEvent event)
{
    if (is_keyboard_input(event, sfKeyEscape) || event.type == sfEvtClosed)
        sys->is_running = sfFalse;
}

void footstep_sound(player_sound_t *sound, sfKeyCode key)
{
    sfMusic_setVolume(sound->sound_footstep, FOOTSTEP_VOL);
    if (sfMusic_getStatus(sound->sound_footstep) != sfPlaying
        && sfKeyboard_isKeyPressed(key) == sfTrue)
        sfMusic_play(sound->sound_footstep);
    if (sfMusic_getStatus(sound->sound_footstep) == sfPlaying
        && (sfKeyboard_isKeyPressed(sfKeyZ) == sfFalse
        && sfKeyboard_isKeyPressed(sfKeyS) == sfFalse
        && sfKeyboard_isKeyPressed(sfKeyD) == sfFalse
        && sfKeyboard_isKeyPressed(sfKeyQ) == sfFalse))
        sfMusic_stop(sound->sound_footstep);
}

static void mov_sprint(player_t *player, time_info_t info)
{
    if (sfKeyboard_isKeyPressed(sfKeyZ)
        && sfKeyboard_isKeyPressed(sfKeyLShift)) {
        sfMusic_setPitch(player->sound->sound_footstep, 2.0f);
        player->mov->mov_speed = (info.delta_time * PLAYER_MOV_SPEED)
            * PLAYER_SPRINT_SPEED;
        }
    if (sfKeyboard_isKeyPressed(sfKeyZ) == sfFalse
        || sfKeyboard_isKeyPressed(sfKeyLShift) == sfFalse)
            sfMusic_setPitch(player->sound->sound_footstep, 1.0f);
}

static bool player_is_out_of_map(player_t *player, map_t map)
{
    return (
        player->camera.pos.x < 0 ||
        player->camera.pos.y < 0 ||
        player->camera.pos.x >= map.w ||
        player->camera.pos.y >= map.h
    );
}

void shield_damage(player_t *player)
{
    if (player->armor <= 0){
        return;
    }
    if (sfKeyboard_isKeyPressed(sfKeyA) && player->armor > 0){
        player->armor = player->armor - 1;
        player->bar->size_shield.x -= 1;
        sfRectangleShape_setSize(player->bar->shield_bar,
            (sfVector2f){(size_t)player->bar->size_shield.x % MAX_SHIELD,
            player->bar->size_shield.y});
    }
}

void hp_damage(sys_data_t *sys, player_t *player)
{
    if (player->health <= 0){
        player->health = MAX_HP;
        set_bar(&player->bar, player);
        sfMusic_pause(sys->scene.musics.game_music);
        sfMusic_play(sys->scene.musics.menu_music);
        return_to_menu(sys);
    }
    if (sfKeyboard_isKeyPressed(sfKeyA) && player->health > 0){
        player->health = player->health - 1;
        player->bar->size_hp.x -= 1;
        sfRectangleShape_setSize(player->bar->hp_bar,
            (sfVector2f){(size_t)player->bar->size_hp.x % MAX_HP,
            player->bar->size_hp.y});
    }
}

static void check_bar(sys_data_t *sys, player_t *player)
{
    shield_damage(player);
    if (player->armor <= 0)
        hp_damage(sys, player);
}

int game_events(sys_data_t *sys)
{
    sfEvent event;
    game_t *game = &(sys->scene.game);
    player_t *player = &(sys->scene.game.player);
    time_info_t info = sys->time;
    map_t map = *(sys->scene.game.current_map);

    mov_sprint(player, info);
    mov_player(player, map);
    check_bar(sys, player);
    if (player_is_out_of_map(player, map))
        player->camera.pos = (sfVector2f){map.start.x + 0.5,
        map.start.y + 0.5};
    while (sfRenderWindow_pollEvent(sys->window, &event)) {
        close_window(sys, event);
        if (set_fullscreen(sys, event) == EXIT_FAIL)
            return EXIT_FAIL;
        enter_next_level(game, event, &(sys->is_running));
    }
    return EXIT_SUCCESS;
}
