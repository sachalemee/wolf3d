/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** draw_enemies.c
*/

#include "wolfengine.h"
#include <math.h>

/*
    sfVector2f player_monster_vec = (sfVector2f){
        enemy_coords.x - player.pos.x,
        enemy_coords.y - player.pos.y
    };
    float scalar = player.dir.x * player_monster_vec.x
        + player.dir.y * player_monster_vec.y;
    float norm_player_dir = 1
    double angle_monster_view = acos();
    dprintf(2, "angle_monster_view : %lf\n", angle_monster_view);

*/
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
