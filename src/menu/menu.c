/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-marin.jeunot
** File description:
** menu
*/

#include "wolfengine.h"
#include "buttons.h"
#include "my.h"
#include <stdlib.h>
#include <stdio.h>

void play_game(sys_data_t *sys)
{
    sfMusic_pause(sys->scene.musics.menu_music);
    sfMusic_play(sys->scene.musics.game_music);
    sfMusic_setVolume(sys->scene.musics.game_music, GAME_VOL);
    set_bar(&(sys->scene.game.player.bar), &(sys->scene.game.player));
    sys->scene.state = STATE_GAME;
}

int update_menu(game_t *game, sys_data_t *sys)
{
    UNUSED(game);
    if (events_menu(sys) == EXIT_FAIL)
        return EXIT_FAIL;
    sfRenderWindow_clear(sys->window, sfWhite);
    animated_bg(sys->scene.menu.entity, &(sys->time));
    draw_bg_menu(&(sys->scene.menu), sys->window);
    sfRenderWindow_display(sys->window);
    return EXIT_SUCCESS;
}
