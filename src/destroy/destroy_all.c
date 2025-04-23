/*
** EPITECH PROJECT, 2025
** wolfengine
** File description:
** destro_all.c
*/

#include "wolfengine.h"

void destroy_all(sys_data_t *sys)
{
    sfRenderWindow_destroy(sys->game->window);
}
