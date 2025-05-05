/*
** EPITECH PROJECT, 2025
** init_things.c
** File description:
** things for the wolfengine
*/

#include "hmap.h"
#include "wolfengine.h"

    // int type;
    // size_t health;
    // size_t damage;
    // int action;
    // float speed;

int garcia_update(thing_t *garcia, sys_data_t *sys_data)
{
    monster_data_t *garcia_data = (monster_data_t *)(garcia->data);

    if (garcia_data->state == SHOOTING) {

    }
    if (garcia_data->)
    rand();
    garcia->coords;
}

thing_t *init_garcia(sfVector2f coords)
{
    thing_t *new_thing = malloc(sizeof(new_thing));

    new_thing->coords = (sfVector3f){coords.x, coords.y, 0};
    new_thing->destroyer = 
    void (*destroyer)(struct thing_s *self);
    int (*updater)(struct thing_s *self, sys_data_t *sys_data);
    sfSprite *sprite;
    sfVector3f coords;
    new_thing->data = malloc(sizeof(monster_data_t));
    *(monster_data_t *)(new_thing->data) = (monster_data_t){GARCIA, 100,
        10, IDLE, 1.0};
    new_thing->
}
