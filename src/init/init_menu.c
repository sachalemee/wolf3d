/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-marin.jeunot
** File description:
** init_menu
*/

#include "wolfengine.h"
#include "buttons.h"
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

void destroy_menu(menu_t *menu)
{
    destroy_entity(menu->entity);
    destroy_buttons(menu->buttons);
    memset((void *)menu, 0, sizeof(typeof(*menu)));
}

int init_menu(menu_t *menu)
{
    if (init_buttons(&(menu->buttons)) == FAILURE
        || init_entity(&(menu->entity)) == FAILURE) {
        destroy_menu(menu);
        return FAILURE;
    }
    return SUCCESS;
}
