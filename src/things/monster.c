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

// returns a coefficient x considering x in [0; 1]
double get_rand_coef(void)
{
    return ((double)(((size_t)rand()) / UINT_MAX));
}

bool monster_idle_state_change(float time_since_last_action)
{
    double min_proba_move = (double)(1.0 - exp(time_since_last_action
            * (-STATE_CHANGE_EQUATION_HALF_LIFE
            / AVERAGE_STATE_CHANGE_COOLDOWN)));

    return (get_rand_coef() >= min_proba_move);
}

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

bool monster_dist_less_than(thing_t *monster, sfVector3f *pos, float dist)
{
    sfVector3f monster_pos_vec = {
        pos->x - monster->coords.x,
        pos->y - monster->coords.y,
        pos->z * monster->coords.z
    };
    float monster_pos_vec_norm = sqrt(SQUARE(monster_pos_vec.x)
        + SQUARE(monster_pos_vec.y) + SQUARE(monster_pos_vec.z));

    if (monster_pos_vec_norm <= dist)
        return true;
    return false;
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

void destroy_monster(void *monster)
{
    if (monster == NULL)
        return;
    free(((thing_t *)monster)->updater);
    if (((thing_t *)monster)->sprite != NULL)
        sfSprite_destroy(((thing_t *)monster)->sprite);
    free(monster);
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

void monster_go_to_point(thing_t *monster, sfVector3f *point)
{
    monster_data_t *monster_data = monster->data;

    monster->movement = (sfGlslVec4){
        monster->coords.x - point->x,
        monster->coords.y - point->y,
        monster->coords.z - point->z,
        0
    };
    monster_vector_set_speed(&(monster->movement), monster_data->speed);
}

thing_t *init_monster(sfVector3f *coords)
{
    thing_t *new_thing = calloc(1, sizeof(new_thing));

    if (new_thing == NULL) 
        return NULL;
    my_uuid_generator(&(new_thing->id));
    new_thing->destroyer = destroy_monster;
    new_thing->sprite = sfSprite_create();
    new_thing->coords = *coords;
    new_thing->data = calloc(1, sizeof(monster_data_t));
    if (check_mallocs(2, "", new_thing, new_thing->data) == false)
        return NULL;
    ((monster_data_t *)(new_thing->data))->state = IDLE;
    return new_thing;
}
