/*
** EPITECH PROJECT, 2025
** init_sys_data
** File description:
** init_sys_data.c
*/

#include "wolfengine.h"
#include <stdlib.h>

void destroy_time(time_info_t time)
{
    if (time.clock)
        sfClock_destroy(time.clock);
}

int init_time(time_info_t *time)
{
    time->clock = sfClock_create();
    if (time->clock == NULL)
        return FAILURE;
    return SUCCESS;
}

void update_time(time_info_t *time)
{
    float current_time = sfTime_asSeconds(sfClock_getElapsedTime(time->clock));

    time->delta_time = current_time - time->last_update;
    time->last_update += time->delta_time;
}
