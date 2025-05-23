/*
** EPITECH PROJECT, 2025
** init_sys_data
** File description:
** init_sys_data.c
*/

#include "wolfengine.h"
#include "things.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>

void destroy_sys(sys_data_t *sys)
{
    if (sys->window)
        sfRenderWindow_destroy(sys->window);
    destroy_time(&(sys->time));
    destroy_scene(&(sys->scene));
    destroy_settings(&(sys->settings));
    memset((void *)sys, 0, sizeof(typeof(*sys)));
}

int init_sys_data(sys_data_t *sys, const char *_Nullable map_path)
{
    srand(time(NULL));
    sys->is_running = sfTrue;
    if (init_window(&(sys->window), sys->win_dimension) == FAILURE
        || init_time(&(sys->time)) == FAILURE
        || load_thing_textures(sys->textures) == FAILURE
        || init_scene(&(sys->scene), map_path, sys->window) == FAILURE
        || init_settings(&(sys->settings),
            sys->scene.game.player.mov) == FAILURE) {
        destroy_sys(sys);
        return FAILURE;
    }
    return SUCCESS;
}
