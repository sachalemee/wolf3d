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

int game_loop(game_t *game)
{
    player_t *player = init_player();
    info_t *info = init_info();
    entity_t *menu_struct = init_menu();

    game->music_change = true;
    game->state = STATE_MENU;
    while (sfRenderWindow_isOpen(game->window) == sfTrue) {
        choose_music(game);
        if (game->state == STATE_MENU)
            menu(game, menu_struct);
        else if (game->state == STATE_GAME)
            game_scene(game, player, info);
    }
    return EXIT_S;
}
