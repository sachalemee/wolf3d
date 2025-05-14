/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** weapon.h
*/

#ifndef WEAPON_H
    #define WEAPON_H
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <stdbool.h>
    //      |       |
    #define TTR_MAIN_WEAPON "main-weapon-sprite.png"
    #define TTR_SECONDARY_WEAPON "secondary-weapon-sprite.png"
    #define TTR_LEG_WEAPON "legs-sprite.png"
    //        |         |
    #define RESSOURCES_SPRITE "ressources/sprite-sheet/"
    #define WEAPON_RESSOURCES RESSOURCES_SPRITE"weapon/"
    #define WATER_SONG_SHOOT WEAPON_RESSOURCES"water-shot-trimmer.wav"
    #define FART_SONG_SHOOT WEAPON_RESSOURCES"fart-sound.ogg"
    //          |           |
    #define RES_MAIN_WEAPON WEAPON_RESSOURCES TTR_MAIN_WEAPON
    #define RES_SECONDARY_WEAPON WEAPON_RESSOURCES TTR_SECONDARY_WEAPON
    #define RES_LEG_WEAPON WEAPON_RESSOURCES TTR_LEG_WEAPON
    //          |           |
    #define MAIN_WEAPON_MAX_FRAME 3
    #define SECONDARY_WEAPON_MAX_FRAME 2
    #define LEG_WEAPON_MAX_FRAME 2
    //          |           |
    #define MAIN_WEAPON_RECT 275 / MAIN_WEAPON_MAX_FRAME
    #define SECONDARY_WEAPON_RECT 318 / SECONDARY_WEAPON_MAX_FRAME
    #define LEG_WEAPON_RECT 315 / LEG_WEAPON_MAX_FRAME
    //          |           |
    #define TTR_MAIN_RECT_SIZE 0, 0, MAIN_WEAPON_RECT, 127
    #define TTR_SECONDARY_RECT_SIZE 0, 0, SECONDARY_WEAPON_RECT, 148
    #define TTR_LEG_RECT_SIZE 0, 0, LEG_WEAPON_RECT, 146
    //          |           |
    #define WEAPON_SPEED_FRAME 1.0
    //          |           |
    #define WIN_WEAPON_POS 325
    #define WIN_LEG_POS 200
    #define WEAPON_POS_PADDING 8
    //          |           |

typedef struct time_info_s time_info_t;

typedef struct weapon_s {
    sfTexture *ttr_main;
    sfTexture *ttr_secondary;
    sfTexture *ttr_leg;
    sfIntRect ttr_main_rect;
    sfIntRect ttr_secondary_rect;
    sfIntRect ttr_leg_rect;
    sfSprite *weapon_sprite;
    sfMusic *main_weapon_shoot_sound;
    sfMusic *leg_weapon_shoot_sound;
    size_t max_frame;
} weapon_t;

void destroy_weapon(weapon_t weapon);
int init_weapon(weapon_t *weapon);
void draw_weapon(weapon_t *weapon,
    sfRenderWindow *win, time_info_t *time);
void set_secondary_weapon(weapon_t *weapon);
void set_primary_weapon(weapon_t *weapon);
void set_leg_weapon(weapon_t *weapon);

#endif /* WEAPON_H */
