/*
** EPITECH PROJECT, 2025
** init_sys_data
** File description:
** init_sys_data.c
*/

#include "wolfengine.h"
#include <stdlib.h>

// the MAIN structure 'sys_data_t' is assumed to be ALWAYS allocated on stack
// thus freeing the pointer must be done manually if allocated in the heap
void destroy_sys(sys_data_t sys)
{
    if (sys.window)
        sfRenderWindow_destroy(sys.window);
    destroy_time(sys.time);
    destroy_scene(sys.scene);
    destroy_settings(sys.settings);
}


/*
    init_buttons(&game);
    init_game(&game);
    if (game_loop(&game) == EXIT_F)


    bool is_running;
    menu_t menu;
    musics_t musics;
    state_t state;
    game_t game;
    player_t player;
    map_t *current_map;
    ssize_t level;
    float difficulty;
    int scene;
    time_info_t time;
*/

int init_sys_data(sys_data_t *sys, const char *_Nullable map_path)
{
    sys->is_running = sfTrue;
    if (init_window(&(sys->window)) == FAILURE
        || init_time(&(sys->time)) == FAILURE
        || init_scene(&(sys->scene), map_path, sys->window) == FAILURE
        || init_settings(&(sys->settings),
            sys->scene.game.player.mov) == FAILURE) {
        destroy_sys(*sys);
        return FAILURE;
    }
    return SUCCESS;
}
