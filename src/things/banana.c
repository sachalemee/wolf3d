/*
** EPITECH PROJECT, 2025
** signal.c
** File description:
** signal enemies for the wolfengine
*/
#include "hmap.h"
#include "wolfengine.h"
#include "things.h"
#include <stdlib.h>
#include <limits.h>

void update_banana(thing_t *banana, sys_data_t *sys_data)
{
    sfGlslVec4 movement_save = banana->movement;
    sfVector3f player_pos3d = {sys_data->scene.game.player.camera.pos.x,
        sys_data->scene.game.player.camera.pos.y, 0};

    if (banana->is_burned)
        return;
    move_monster(&(banana->coords), &(banana->movement),
        sys_data->time.delta_time);
    banana->movement = movement_save;
    if (monster_dist_less_than(banana, &player_pos3d,
        ((monster_data_t *)banana->data)->range)) {
        damage_player(&(sys_data->scene.game.player),
            (int)((monster_data_t *)banana->data)->damage);
    }
    return;
}

thing_t *throw_banana(sfVector3f *player_pos, sfVector3f *origin_coords)
{
    thing_t *new_banana = init_banana(origin_coords);

    if (new_banana == NULL)
        return NULL;
    monster_go_to_point(new_banana, player_pos);
    return new_banana;
}

thing_t *init_banana(sfVector3f *coords)
{
    thing_t *new_banana = init_monster(coords);

    if (new_banana == NULL)
        return NULL;
    new_banana->updater = update_banana;
    new_banana->id = BANANA;
    *(monster_data_t *)(new_banana->data) = (monster_data_t){
        BANANA_DFLT_HP,
        BANANA_DFLT_DMG,
        BANANA_DFLT_SPEED,
        BANANA_RANGE,
        BANANA_RADIUS,
        IDLE
    };
    return new_banana;
}
