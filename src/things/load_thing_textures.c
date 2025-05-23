/*
** EPITECH PROJECT, 2025
** init_sys_data
** File description:
** init_sys_data.c
*/

#include "wolfengine.h"
#include "things.h"
#include <string.h>

static void destroy_thing_textures(sfTexture *textures[LEN_OF_THING_TEXTURES])
{
    if (textures == NULL)
        return;
    for (size_t i = 0; i < LEN_OF_THING_TEXTURES; i++) {
        if (textures[i] == NULL)
            return;
        sfTexture_destroy(textures[i]);
    }
    memset((void *)textures, 0, LEN_OF_THING_TEXTURES);
}

int load_thing_textures(sfTexture *textures[LEN_OF_THING_TEXTURES])
{
    for (size_t i = 0; i < LEN_OF_THING_TEXTURES; i++) {
        textures[i] = sfTexture_createFromFile(thing_textures[i], NULL);
        if (textures[i] == NULL) {
            destroy_thing_textures(textures);
            return FAILURE;
        }
    }
    return SUCCESS;
}
