/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** draw_enemies.c
*/

#include "wolfengine.h"
#include <math.h>

static int draw_enemy(sfVector2f enemy_coords, float *raycast_data,
    sfRenderWindow *win, player_t player)
{
    return SUCCESS;
}

void draw_enemies(sfVector2f *enemy_coords, float *raycast_data,
    sfRenderWindow *win, player_t player)
{
    sfVector2f cmpvar = {-1, -1};

    for (size_t i = 0; !(enemy_coords[i].x == -1 && enemy_coords[i].y == -1);
        i++) {
        draw_enemy(enemy_coords[i], raycast_data, win, player);
    }
}
