/*
** EPITECH PROJECT, 2025
** wolfengine
** File description:
** init_game.c
*/

#include "wolfengine.h"
#include <stdlib.h>

void destroy_musics(musics_t musics)
{
    if (musics.game_music != NULL)
        sfMusic_destroy(musics.game_music);
    if (musics.menu_music != NULL)
        sfMusic_destroy(musics.menu_music);
}

int init_musics(musics_t *musics)
{
    musics->game_music = sfMusic_createFromFile(MUSIC_PATH_GAME);
    musics->menu_music = sfMusic_createFromFile(MUSIC_PATH_MENU);
    if (musics->game_music == NULL || musics->menu_music == NULL) {
        destroy_musics(*musics);
        return FAILURE;
    }
    sfMusic_setLoop(musics->game_music, sfTrue);
    sfMusic_setLoop(musics->menu_music, sfTrue);
    return SUCCESS;
}
