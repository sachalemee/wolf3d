/*
** EPITECH PROJECT, 2025
** wolfengine
** File description:
** game_loop.c
*/

#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stddef.h>
#include "wolfengine.h"
#include "buttons.h"
#include "hmap.h"
#include "my.h"

int update_scenes(sys_data_t *sys_data)
{
    size_t i = 0;

    while (STATEMENT[i].state != 3) {
        if (sys_data->scene.state == STATEMENT[i].state) {
            return STATEMENT[i].func(&(sys_data->scene.game), sys_data);
        }
        i++;
    }
    sys_data->scene.state = STATE_MENU;
    if (update_menu(&(sys_data->scene.game), sys_data) == EXIT_FAIL)
        return EXIT_FAIL;
    return EXIT_SUCCESS;
}

int main_loop(sys_data_t *sys_data)
{
    size_t return_tmp_value = 0;

    sfMusic_setVolume(sys_data->scene.musics.menu_music, 50);
    sfMusic_play(sys_data->scene.musics.menu_music);
    while (sfRenderWindow_isOpen(sys_data->window) == sfTrue
        && sys_data->is_running) {
        update_time(&(sys_data->time));
        return_tmp_value = update_scenes(sys_data);
        if (return_tmp_value == (size_t)FAILURE)
            return FAILURE;
        if (return_tmp_value == EXIT_FAIL)
            return EXIT_FAIL;
    }
    if (sfRenderWindow_isOpen(sys_data->window) == sfTrue)
        sfRenderWindow_close(sys_data->window);
    return SUCCESS;
}
