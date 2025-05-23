/*
** EPITECH PROJECT, 2025
** wolfengine
** File description:
** init_game.c
*/

#include "wolfengine.h"
#include <stdlib.h>
#include <string.h>

void destroy_settings(settings_t *settings)
{
    memset((void *)settings, 0, sizeof(typeof(*settings)));
    return;
}

int init_settings(settings_t *settings, player_settings_t *player_settings)
{
    settings->player_settings = player_settings;
    settings->difficulty = DEFAULT_DIFFICULTY;
    return SUCCESS;
}
