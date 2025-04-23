/*
** EPITECH PROJECT, 2025
** init_sys_data
** File description:
** init_sys_data.c
*/

#include "wolfengine.h"
#include <stdlib.h>

// the MAIN structure 'sys_data_t' is assumed to be ALWAYS allocated on stack
// thus freeing the pointer must be done manually if allocated in the heap
void destroy_sys(sys_data_t sys)
{
    destroy_game(sys.game);
    destroy_map(sys.current_map);
    destroy_player(sys.player);
}

int init_sys_data(sys_data_t *sys, const char *_Nullable map_path)
{
    if (map_path == NULL) {
        sys->level = 0;
        sys->current_map = get_level(sys->level);
    } else {
        sys->level = -1;
        sys->current_map = get_map(map_path);
    }
    if (sys->current_map)
        sys->player = init_player(sys->current_map->start);
    sys->game = init_game();
    if (!sys->game || !sys->current_map || !sys->player) {
        destroy_sys(*sys);
        return FAILURE;
    }
    return SUCCESS;
}
