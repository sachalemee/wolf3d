/*
** EPITECH PROJECT, 2025
** G-ING-200-PAR-2-1-myworld-sacha.lemee
** File description:
** set_button_color.c
*/

#include "buttons.h"
#include "wolfengine.h"

void set_button_color(buttons_t *button)
{
    button->color[B_DEFAULT] = sfWhite;
    button->color[B_HOVER] = sfColor_fromRGB(89, 211, 250);
    button->color[B_PRESSED] = sfColor_fromRGB(16, 144, 216);
    button->color[B_DISABLE] = sfWhite;
    button->color[B_BLACK] = sfBlack;
}
