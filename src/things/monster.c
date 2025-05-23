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

bool monster_dist_less_than(thing_t *monster, sfVector3f *pos, float dist)
{
    sfVector3f monster_pos_vec = {
        pos->x - monster->coords.x,
        pos->y - monster->coords.y,
        pos->z * monster->coords.z
    };
    float monster_pos_vec_norm = NORM(monster_pos_vec);

    if (monster_pos_vec_norm <= dist)
        return true;
    return false;
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
