/*
** EPITECH PROJECT, 2025
** wolfengine
** File description:
** game_loop.c
*/

#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "wolfengine.h"
#include "buttons.h"
#include "hmap.h"

static void get_music_data(scene_t *scenes,
    sfSoundStatus *game_music_status, sfSoundStatus *menu_music_status)
{
    *game_music_status =
        sfMusic_getStatus(scenes->musics.game_music);
    *menu_music_status =
        sfMusic_getStatus(scenes->musics.menu_music);
    if (*game_music_status == sfPlaying && *menu_music_status == sfPlaying) {
        sfMusic_pause(scenes->musics.game_music);
        sfMusic_pause(scenes->musics.menu_music);
        *game_music_status = sfPaused;
        *menu_music_status = sfPaused;
    }
}

static void update_music(scene_t *scenes)
{
    sfSoundStatus game_music_status = 0;
    sfSoundStatus menu_music_status = 0;

    get_music_data(scenes, &game_music_status, &menu_music_status);
    switch (scenes->state) {
        case STATE_GAME:
            if (game_music_status != sfPlaying) {
                sfMusic_play(scenes->musics.game_music);
                sfMusic_pause(scenes->musics.menu_music);
            }
            break;
        case STATE_MENU:
            if (menu_music_status != sfPlaying) {
                sfMusic_play(scenes->musics.menu_music);
                sfMusic_pause(scenes->musics.game_music);
            }
            break;
    }
}

static int update_scenes(sys_data_t *sys_data)
{
    int failure_catch = SUCCESS;

    update_music(&(sys_data->scene));
    switch (sys_data->scene.state) {
        case STATE_MENU:
            failure_catch = update_menu(sys_data);
            break;
        case STATE_GAME:
            failure_catch = game_scene(&(sys_data->scene.game), sys_data);
            break;
        default:
            failure_catch = update_error_screen(&(sys_data->scene.error_scene),
                sys_data->window, &(sys_data->time));
            break;
    }
    if (failure_catch == FAILURE)
        return FAILURE;
    return SUCCESS;
}

int game_loop(sys_data_t *sys_data)
{
    while (sfRenderWindow_isOpen(sys_data->window) == sfTrue
        && sys_data->is_running) {
        update_time(&(sys_data->time));
        if (update_scenes(sys_data) == FAILURE)
            return FAILURE;
    }
    if (sfRenderWindow_isOpen(sys_data->window) == sfTrue)
        sfRenderWindow_close(sys_data->window);
    return SUCCESS;
}
