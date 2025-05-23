/*
** EPITECH PROJECT, 2025
** big_ben.c
** File description:
** big_ben enemies for the wolfengine
*/
#include "hmap.h"
#include "wolfengine.h"
#include "things.h"
#include <stdlib.h>

void big_ben_update(thing_t *big_ben, sys_data_t *sys_data)
{
    monster_data_t *big_ben_data = (monster_data_t *)(big_ben->data);
    sfVector3f player_pos3d = {sys_data->scene.game.player.camera.pos.x,
        sys_data->scene.game.player.camera.pos.y, 0};

    if (big_ben->is_burned)
        return;
    move_monster(&(big_ben->coords), &(big_ben->movement),
        sys_data->time.delta_time);
    if (big_ben_data->state == ATTACKING && big_ben->movement.w <= 0)
        damage_player(&(sys_data->scene.game.player), big_ben_data->damage);
    if (big_ben_data->state == IDLE && big_ben->movement.w <= 0)
        monster_try_walking(big_ben);
    if (big_ben_data->state != ATTACKING && monster_dist_less_than(big_ben,
        &player_pos3d, big_ben_data->range)) {
        big_ben->movement = (sfGlslVec4){0, 0, 0, big_ben_data->speed};
        big_ben_data->state = ATTACKING;
    }
    big_ben_data->state = TRYIDLE(big_ben->movement.w, big_ben_data->state);
    if (big_ben->onscreen && big_ben_data->state == IDLE)
        monster_go_to_point(big_ben, &player_pos3d);
}

thing_t *init_big_ben(sfVector3f *coords)
{
    thing_t *new_big_ben = init_monster(coords);

    new_big_ben->updater = big_ben_update;
    new_big_ben->id = BIG_BEN;
    *(monster_data_t *)(new_big_ben->data) = (monster_data_t){
        BIG_BEN_DFLT_HP,
        BIG_BEN_DFLT_DMG,
        BIG_BEN_DFLT_SPEED,
        BIG_BEN_RANGE,
        BIG_BEN_RADIUS,
        IDLE
    };
    return new_big_ben;
}
