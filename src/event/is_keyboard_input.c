/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** is_keyboard_input.c
*/

#include "wolfengine.h"

sfBool is_keyboard_input(sfEvent event, sfKeyCode key)
{
    if (event.type == sfEvtKeyPressed && event.key.code == key)
        return sfTrue;
    return sfFalse;
}
