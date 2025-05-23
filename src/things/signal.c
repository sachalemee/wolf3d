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

int signal_shoot(thing_t *signal, sfVector3f *player_pos, map_t *map)
{
    thing_t *new_projectile = throw_banana(player_pos, &(signal->coords));

    if (new_projectile == NULL)
        return FAILURE;
    stack_item(new_projectile, destroy_monster, &(map->map
            [(size_t)signal->coords.x][(size_t)signal->coords.y].things));
    if (map->map[(size_t)signal->coords.x]
        [(size_t)signal->coords.y].things.is_burnt == true)
        return FAILURE;
    return SUCCESS;
}

void signal_update(thing_t *signal, sys_data_t *sys_data)
{
    monster_data_t *signal_data = (monster_data_t *)(signal->data);
    sfVector3f player_pos3d = {sys_data->scene.game.player.camera.pos.x,
        sys_data->scene.game.player.camera.pos.y, 0};

    if (signal->is_burned)
        return;
    move_monster(&(signal->coords), &(signal->movement),
        sys_data->time.delta_time);
    if (signal_data->state == ATTACKING && signal->movement.w <= 0)
        signal_shoot(signal, &player_pos3d,
            sys_data->scene.game.current_map);
    if (signal_data->state == IDLE && signal->movement.w <= 0)
        monster_try_walking(signal);
    if (signal_data->state != ATTACKING && monster_dist_less_than(signal,
        &player_pos3d, signal_data->range)) {
        signal->movement = (sfGlslVec4){0, 0, 0, signal_data->speed};
        signal_data->state = ATTACKING;
    }
    if (signal->movement.w <= 0)
        signal_data->state = IDLE;
    if (signal->onscreen && signal_data->state == IDLE)
        monster_go_to_point(signal, &player_pos3d);
}

thing_t *init_signal(sfVector3f *coords)
{
    thing_t *new_signal = init_monster(coords);

    new_signal->updater = signal_update;
    new_signal->id = SIGNAL;
    *(monster_data_t *)(new_signal->data) = (monster_data_t){
        SIGNAL_DFLT_HP,
        SIGNAL_DFLT_DMG,
        SIGNAL_DFLT_SPEED,
        SIGNAL_RANGE,
        SIGNAL_RADIUS,
        IDLE
    };
    return new_signal;
}
