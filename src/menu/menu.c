/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-marin.jeunot
** File description:
** menu
*/

#include "wolfengine.h"
#include "buttons.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void play_game(sys_data_t *sys)
{
    sys->scene.state = STATE_GAME;
}

int update_menu(sys_data_t *sys)
{
    events_menu(sys);
    sfRenderWindow_clear(sys->window, sfWhite);
    animated_bg(sys->scene.menu.entity, &(sys->time));
    draw_bg_menu(&(sys->scene.menu), sys->window);
    sfRenderWindow_display(sys->window);
    return EXIT_S;
}
