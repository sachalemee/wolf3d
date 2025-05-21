/*
** EPITECH PROJECT, 2025
** wolfengine
** File description:
** init_game.c
*/

#include "wolfengine.h"
#include "buttons.h"
#include <stdlib.h>
#include "stdio.h"


void destroy_scene(scene_t scene)
{
    destroy_musics(scene.musics);
    destroy_error_screen(scene.error_scene);
    destroy_game(scene.game);
    destroy_weapon(scene.game.weapon);
    destroy_menu(scene.menu);
    destroy_settings(scene.setting_screen);
}

int init_scene(scene_t *scene, const char *_Nullable map_path,
    sfRenderWindow *win)
{
    scene->state = DEFAULT_SCENE;
    if (init_error_screen(&(scene->error_scene), win) == FAILURE
        || init_menu(&(scene->menu)) == FAILURE
        || init_musics(&(scene->musics)) == FAILURE
        || init_setting_screen(&(scene->setting_screen)) == FAILURE
        || init_game(&(scene->game), map_path, win) == FAILURE) {
        destroy_scene(*scene);
        return FAILURE;
    }
    if (scene->setting_screen.setting_sprite == NULL)
        printf("[ IS NULL ]\n");
    return SUCCESS;
}
