/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** init_info.c
*/

#include <stddef.h>
#include <stdlib.h>
#include "wolfengine.h"

info_t *init_info(void)
{
    info_t *info = malloc(sizeof(info_t));

    if (info == NULL)
        return NULL;
    info->d_time = 0.0;
    return info;
}
