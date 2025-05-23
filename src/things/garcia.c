/*
** EPITECH PROJECT, 2025
** garcia.c
** File description:
** garcia enemies for the wolfengine
*/
#include "hmap.h"
#include "wolfengine.h"
#include "things.h"
#include <stdlib.h>

void garcia_update(thing_t *garcia, sys_data_t *sys_data)
{
    monster_data_t *garcia_data = (monster_data_t *)(garcia->data);
    sfVector3f player_pos3d = {sys_data->scene.game.player.camera.pos.x,
        sys_data->scene.game.player.camera.pos.y, 0};

    if (garcia->is_burned)
        return;
    move_monster(&(garcia->coords), &(garcia->movement),
        sys_data->time.delta_time);
    if (garcia_data->state == ATTACKING && garcia->movement.w <= 0)
        damage_player(&(sys_data->scene.game.player), garcia_data->damage);
    if (garcia_data->state == IDLE && garcia->movement.w <= 0)
        monster_try_walking(garcia);
    if (garcia_data->state != ATTACKING && monster_dist_less_than(garcia,
        &player_pos3d, garcia_data->range)) {
        garcia->movement = (sfGlslVec4){0, 0, 0, garcia_data->speed};
        garcia_data->state = ATTACKING;
    }
    garcia_data->state = TRYIDLE(garcia->movement.w, garcia_data->state);
    if (garcia->onscreen && garcia_data->state == IDLE)
        monster_go_to_point(garcia, &player_pos3d);
}

thing_t *init_garcia(sfVector3f *coords)
{
    thing_t *new_garcia = init_monster(coords);

    new_garcia->updater = garcia_update;
    new_garcia->id = GARCIA;
    *(monster_data_t *)(new_garcia->data) = (monster_data_t){
        GARCIA_DFLT_HP,
        GARCIA_DFLT_DMG,
        GARCIA_DFLT_SPEED,
        GARCIA_RANGE,
        GARCIA_RADIUS,
        IDLE
    };
    return new_garcia;
}
