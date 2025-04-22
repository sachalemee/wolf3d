/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-marin.jeunot
** File description:
** choose_music
*/

#include "wolfengine.h"
#include <stdio.h>
#include <stdbool.h>

void choose_music(game_t *game)
{
    if (game->state == STATE_MENU && game->music_change == true){
        sfMusic_play(game->music_bg);
        game->music_change = false;
    }
    if (game->state == STATE_GAME && game->music_change == true){
        sfMusic_play(game->music_game);
        game->music_change = false;
    }
}
