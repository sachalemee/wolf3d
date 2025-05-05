/*
** EPITECH PROJECT, 2025
** init_things.c
** File description:
** things for the wolfengine
*/

#include "hmap.h"
#include "wolfengine.h"

int destroy_monster(thing_t *monster)
{
    destroy_monster_data(monster->updater)
    free(monster);
}
