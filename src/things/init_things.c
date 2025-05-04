/*
** EPITECH PROJECT, 2025
** init_things.c
** File description:
** things for the wolfengine
*/

#include "hmap.h"
#include "wolfengine.h"



int add_thing(map_t *map, thing_t *new_thing)
{
    sfVector2i thing_tile_coords = {0};

    if (new_thing == NULL)
        return FAILURE;
    thing_tile_coords = (sfVector2i){
        (int)new_thing->coords.x,
        (int)new_thing->coords.x
    };
    if (map->thing_table.is_burnt)
        return FAILURE;
    for (linked_node_t **node_x = &(map->thing_table.top); *node_x != NULL; node_x = &((*node_x)->next)) {
        if ((*node_x)->next == NULL || (*node_x)->next->val)
        for (linked_node_t **node_y = &(map->thing_table.top); *node_y != NULL; node_y = &((*node_y)->next)) {

        }
    }
}

/*
 init_monster()
{

}
*/
