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
#include "wolfengine.h"
#include "buttons.h"
#include "hmap.h"
#include "my.h"

int update_scenes(sys_data_t *sys_data)
{
    int i = 0;

    //update_music(&(sys_data->scene));
    while (STATEMENT[i].state != 0) {
        if (sys_data->scene.state == STATEMENT[i].state) {
            return STATEMENT[i].func(&(sys_data->scene.game), sys_data);
        }
        i++;
    }
    sys_data->scene.state = STATE_MENU;
    if (update_menu(&(sys_data->scene.game), sys_data) == EXIT_F)
        return EXIT_F;
    return EXIT_S;
}


int main_loop(sys_data_t *sys_data)
{
    sfMusic_play(sys_data->scene.musics.menu_music);
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
