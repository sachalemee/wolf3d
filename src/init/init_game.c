/*
** EPITECH PROJECT, 2025
** wolfengine
** File description:
** init_game.c
*/

#include "wolfengine.h"
#include <stdlib.h>

int init_game(game_t *game)
{
    game->window = set_window();
    game->clock = sfClock_create();
    game->music_game = sfMusic_createFromFile(MUSIC_PATH_GAME);
    game->music_bg = sfMusic_createFromFile(MUSIC_PATH_BG);
    sfMusic_setLoop(game->music_bg, sfTrue);
    sfMusic_setLoop(game->music_game, sfTrue);
    game->bg = sfColor_fromRGB(0, 0, 0);
    return EXIT_S;
}
