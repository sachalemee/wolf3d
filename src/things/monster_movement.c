/*
** EPITECH PROJECT, 2025
** init_things.c
** File description:
** things for the wolfengine
*/
#include "hmap.h"
#include "wolfengine.h"
#include "things.h"
#include <stdlib.h>
#include <limits.h>
#include <math.h>

void monster_vector_set_speed(sfGlslVec4 *to_set, float speed)
{
    if (speed != 0)
        to_set->w = sqrt(SQUARE(to_set->x)
            + SQUARE(to_set->y) + SQUARE(to_set->z)) / speed;
}

void monster_random_walk_vector(sfGlslVec4 *to_set, float speed)
{
    *to_set = (sfGlslVec4){
        get_rand_coef() * AVERAGE_WALK_DIST * 2,
        get_rand_coef() * AVERAGE_WALK_DIST * 2,
        0, 0};
    monster_vector_set_speed(to_set, speed);
}

void move_monster(sfVector3f *monster_coords,
    sfGlslVec4 *monster_movement, float delta_time)
{
    sfVector3f delta_vector = {0};

    monster_movement->w -= delta_time;
    if (monster_movement->w < 0)
        return;
    delta_vector = (sfVector3f){
        monster_movement->x / (monster_movement->w * delta_time),
        monster_movement->y / (monster_movement->w * delta_time),
        monster_movement->z / (monster_movement->w * delta_time)
    };
    *monster_coords = (sfVector3f){monster_coords->x - delta_vector.x,
        monster_coords->y - delta_vector.y, monster_coords->z - delta_vector.z
    };
    *monster_movement = (sfGlslVec4){
        monster_movement->x - delta_vector.x,
        monster_movement->y - delta_vector.y,
        monster_movement->z - delta_vector.z, monster_movement->w
    };
}

bool monster_go_to_point(thing_t *monster, sfVector3f *point)
{
    monster_data_t *monster_data = monster->data;

    monster->movement = (sfGlslVec4){
        monster->coords.x - point->x,
        monster->coords.y - point->y,
        monster->coords.z - point->z,
        0
    };
    monster_vector_set_speed(&(monster->movement), monster_data->speed);
    return true;
}

bool monster_try_walking(thing_t *monster)
{
    monster_data_t *monster_data = monster->data;

    if (monster_idle_state_change(monster->movement.w)) {
        monster_random_walk_vector(&(monster->movement),
            monster_data->speed);
        monster_data->state = WALKING;
        return true;
    }
    return false;
}
