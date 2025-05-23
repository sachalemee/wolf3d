/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** raycasting.h
*/
#ifndef RAYCASTING_H
    #define RAYCASTING_H
    //           |           |
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <stdbool.h>
    #include <stddef.h>
    #include <sys/types.h>
    //           |           |
    #define TEXTURE_WALL "ressources/Wolf3D_IMG/wall_bamboo.png"
    //           |           |
enum vector_step {
    POSITIVE_STEP = 1,
    NEGATIVE_STEP = -1
};

enum ray_hit_type {
    VERTICAL_WALL = 0,
    HORIZONTAL_WALL = 1
};

    #define WALL_TEXTURES_PATH "ressources/Wolf3D_IMG/wall_textures/"

enum wall_types {
    AIR = 0,
    SIMPLE_WALL = 1,
    SPECIAL_WALL = 2,
    WALL_1 = 3,
    WALL_2 = 4,
    WALL_3 = 5,
    WALL_4 = 6,
    WALL_5 = 7,
    WALL_6 = 8,
    WALL_7 = 9
};
static char const *const wall_textures[] = {
    "wall_bamboo.png",
    "palmer_trees.png",
    "portal.png",
    "wall_bamboo_surf_plank.png",
    "wall_bamboo_bouy.png",
    "marin_stand_icecream.png",
    "sacha_stand_water.png",
    "paradise_palm3d.png",
    "wall_bamboo.png",
    NULL
};

int init_wall_sprites(sfSprite ***wall_sprites);
void destroy_wall_sprites(sfSprite **wall_sprites);

#endif /* RAYCASTING_H */
