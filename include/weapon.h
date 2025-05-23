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
    #define WEAPON_RESSOURCES "ressources/sprite-sheet/weapon/"
    #define ICON_PATH WEAPON_RESSOURCES "icon/"
    //      |       |
    #define TTR_MAIN_WEAPON "main-weapon-sprite.png"
    #define TTR_SECONDARY_WEAPON "secondary-weapon-sprite.png"
    #define TTR_LEG_WEAPON "legs-sprite.png"
    #define TTR_ICEMAKER_WEAPON "mr-ice-maker-sprite.png"
    #define TTR_FLASHLIGHT "flashlight.png"
    //      |       |
    #define TTR_MAIN_WEAPON_ICON ICON_PATH"main-weapon-icon-sprite.png"
    #define TTR_SCND_WEAPON_ICON ICON_PATH"secondary-weapon-icon-sprite.png"
    #define TTR_LEG_WEAPON_ICON ICON_PATH"legs-sprite-icon.png"
    #define TTR_ICEMK_WEAPON_ICON ICON_PATH"icemaker-weapon-icon-sprite.png"
    //      |       |
    #define TTR_MAIN_WEAPON_AMMO WEAPON_RESSOURCES"shoot-main-icon.png"
    #define TTR_SCND_WEAPON_AMMO WEAPON_RESSOURCES"water-bullet-sprite.png"
    #define TTR_LEG_WEAPON_AMMO WEAPON_RESSOURCES"cross-icon.png"
    #define TTR_ICEMK_WEAPON_AMMO WEAPON_RESSOURCES"ice-cube.png"
    //      |       |
    #define TTR_MAIN_WEAPON_CROSSHAIR ICON_PATH"primary_crosshair.png"
    #define TTR_SCND_WEAPON_CROSSHAIR ICON_PATH"secondary_crosshair.png"
    #define TTR_LEG_WEAPON_CROSSHAIR ICON_PATH"feet_crosshair.png"
    #define TTR_ICEMK_WEAPON_CROSSHAIR ICON_PATH"icemaker_crosshair.png"
    //        |         |
    #define ICEMAKER_WEAPON_ICON_POS 60, 890
    #define LEG_WEAPON_ICON_POS 55, 899
    #define SECONDARY_WEAPON_ICON_POS 60, 890
    #define MAIN_WEAPON_ICON_POS 60, 880
    //        |         |
    #define ICEMAKER_WEAPON_ICON_SCALE 1.7, 1.7
    #define LEG_WEAPON_ICON_SCALE 0.75, 0.75
    #define SECONDARY_WEAPON_ICON_SCALE 1.3, 1.3
    #define MAIN_WEAPON_ICON_SCALE 3, 3
    //        |         |
    #define ICEMAKER_WEAPON_AMMO_POS 95, 1030
    #define LEG_WEAPON_AMMO_POS 85, 1013
    #define SECONDARY_WEAPON_AMMO_POS 98, 1030
    #define MAIN_WEAPON_AMMO_POS 55, 983
    //        |         |
    #define ICEMAKER_WEAPON_AMMO_SCALE 0.07, 0.07
    #define LEG_WEAPON_AMMO_SCALE 0.35, 0.35
    #define SECONDARY_WEAPON_AMMO_SCALE 1.5, 1.5
    #define MAIN_WEAPON_AMMO_SCALE 0.5, 0.5
    //        |         |
    #define ICEMAKER_WEAPON_CROSSHAIR_POS 95, 1030
    #define LEG_WEAPON_CROSSHAIR_POS 85, 1013
    #define SECONDARY_WEAPON_CROSSHAIR_POS 98, 1030
    #define MAIN_WEAPON_CROSSHAIR_POS 55, 983
    //        |         |
    #define ICEMAKER_WEAPON_CROSSHAIR_SCALE 1, 1
    #define LEG_WEAPON_CROSSHAIR_SCALE 0.75, 0.75
    #define SECONDARY_WEAPON_CROSSHAIR_SCALE 1, 1
    #define MAIN_WEAPON_CROSSHAIR_SCALE 0.5, 0.5
    //        |         |
    #define WATER_SONG_SHOOT WEAPON_RESSOURCES"water-shot-trimmer.wav"
    #define FART_SONG_SHOOT WEAPON_RESSOURCES"fart-sound.ogg"
    #define ICEMAKER_SONG_SHOOT WEAPON_RESSOURCES"icemaker_shot_sound.ogg"
    //          |           |
    #define RES_MAIN_WEAPON WEAPON_RESSOURCES TTR_MAIN_WEAPON
    #define RES_SECONDARY_WEAPON WEAPON_RESSOURCES TTR_SECONDARY_WEAPON
    #define RES_LEG_WEAPON WEAPON_RESSOURCES TTR_LEG_WEAPON
    #define RES_ICEMAKER_WEAPON WEAPON_RESSOURCES TTR_ICEMAKER_WEAPON
    #define RES_FLASHLIGHT WEAPON_RESSOURCES TTR_FLASHLIGHT
    //          |           |
    #define MAIN_WEAPON_MAX_FRAME 3
    #define SECONDARY_WEAPON_MAX_FRAME 2
    #define LEG_WEAPON_MAX_FRAME 2
    #define ICEMAKER_WEAPON_MAX_FRAME 2
    //          |           |
    #define MAIN_WEAPON_RECT 275 / MAIN_WEAPON_MAX_FRAME
    #define SECONDARY_WEAPON_RECT 318 / SECONDARY_WEAPON_MAX_FRAME
    #define LEG_WEAPON_RECT 315 / LEG_WEAPON_MAX_FRAME
    #define ICEMAKER_WEAPON_RECT 704 / 2
    //          |           |
    #define TTR_MAIN_RECT_SIZE 0, 0, MAIN_WEAPON_RECT, 127
    #define TTR_SECONDARY_RECT_SIZE 0, 0, SECONDARY_WEAPON_RECT, 148
    #define TTR_LEG_RECT_SIZE 0, 0, LEG_WEAPON_RECT, 146
    #define TTR_ICEMAKER_RECT_SIZE 0, 0, ICEMAKER_WEAPON_RECT, 135
    //          |           |
    #define WEAPON_SPEED_FRAME 1.0
    //          |           |
    #define WIN_MAIN_WEAPON_POS 325
    #define WIN_SECONDARY_WEAPON_POS 250
    #define WIN_LEG_POS 200
    #define WEAPON_POS_PADDING 8

typedef struct time_info_s time_info_t;

typedef struct weapon_crosshair_s {
    sfTexture *ttr_main_crosshair;
    sfTexture *ttr_secondary_crosshair;
    sfTexture *ttr_leg_crosshair;
    sfTexture *ttr_icemaker_crosshair;
    sfSprite *weapon_crosshair_sprite;
} weapon_crosshair_t;

typedef struct weapon_ammo_s {
    sfTexture *ttr_main_ammo;
    sfTexture *ttr_secondary_ammo;
    sfTexture *ttr_leg_ammo;
    sfTexture *ttr_icemaker_ammo;
    sfSprite *weapon_ammo_sprite;
} weapon_ammo_t;

typedef struct weapon_icon_s {
    sfTexture *ttr_main_icon;
    sfTexture *ttr_secondary_icon;
    sfTexture *ttr_leg_icon;
    sfTexture *ttr_icemaker_icon;
    sfSprite *weapon_icon_sprite;
} weapon_icon_t;

typedef struct weapon_s {
    sfTexture *ttr_main;
    sfTexture *ttr_secondary;
    sfTexture *ttr_leg;
    sfTexture *ttr_icemaker;
    sfTexture *ttr_flashlight;
    sfIntRect ttr_main_rect;
    sfIntRect ttr_secondary_rect;
    sfIntRect ttr_leg_rect;
    sfIntRect ttr_icemaker_rect;
    sfSprite *weapon_sprite;
    sfSprite *flashlight_sprite;
    sfMusic *main_weapon_shoot_sound;
    sfMusic *leg_weapon_shoot_sound;
    sfMusic *icemaker_weapon_shoot_sound;
    size_t max_frame;
    weapon_icon_t *weapon_icon;
    weapon_ammo_t *weapon_ammo;
    weapon_crosshair_t *weapon_crosshair;
    sfVector2u win_dimension;
} weapon_t;

void destroy_weapon(weapon_t weapon);
int init_weapon(weapon_t *weapon);
//          |           |
int init_each_weapon(weapon_t *weapon);
int init_each_weapon_icon(weapon_icon_t *weapon_icon);
int init_each_weapon_ammo(weapon_ammo_t *weapon_ammo);
int init_each_weapon_crosshair(weapon_crosshair_t *weapon_crosshair);
//          |           |
void draw_weapon(weapon_t *weapon,
    sfRenderWindow *win, time_info_t *time);
//          |           |
void set_secondary_weapon(weapon_t *weapon);
void set_primary_weapon(weapon_t *weapon);
void set_leg_weapon(weapon_t *weapon);
void set_icemaker_weapon(weapon_t *weapon);
//          |           |
void set_flashlight_weapon(weapon_t *weapon);
//          |           |
void set_weapon_sound(weapon_t *weapon,
    size_t current_weapon);
void weapon_shooting(time_info_t *time,
    weapon_t *weapon, size_t *current_frame, size_t current_weapon);
void change_weapon(weapon_t *weapon, size_t *current_weapon);
void choose_weapon(weapon_t *weapon,
    size_t current_weapon);
//          |           |
void set_main_to_secondary(weapon_t *weapon,
    sfSprite *current_part, size_t current_weapon, size_t current_frame);
void set_special_leg_icemaker(weapon_t *weapon,
    sfSprite *current_part, size_t current_weapon, size_t current_frame);
//          |           |
int init_main_weapon_icon(weapon_icon_t *weapon);
int init_secondary_weapon_icon(weapon_icon_t *weapon);
int init_leg_weapon_icon(weapon_icon_t *weapon);
int init_icemaker_weapon_icon(weapon_icon_t *weapon);
//          |           |
void set_icemaker_weapon_icon(weapon_icon_t *weapon_icon);
void set_leg_weapon_icon(weapon_icon_t *weapon_icon);
void set_secondary_weapon_icon(weapon_icon_t *weapon_icon);
void set_primary_weapon_icon(weapon_icon_t *weapon_icon);
//          |           |
int init_main_weapon_ammo(weapon_ammo_t *weapon);
int init_secondary_weapon_ammo(weapon_ammo_t *weapon);
int init_leg_weapon_ammo(weapon_ammo_t *weapon);
int init_icemaker_weapon_ammo(weapon_ammo_t *weapon);
//          |           |
void set_icemaker_weapon_ammo(weapon_ammo_t *weapon_ammo);
void set_leg_weapon_ammo(weapon_ammo_t *weapon_ammo);
void set_secondary_weapon_ammo(weapon_ammo_t *weapon_ammo);
void set_primary_weapon_ammo(weapon_ammo_t *weapon_ammo);
//          |           |
int init_main_weapon_crosshair(weapon_crosshair_t *weapon);
int init_secondary_weapon_crosshair(weapon_crosshair_t *weapon);
int init_leg_weapon_crosshair(weapon_crosshair_t *weapon);
int init_icemaker_weapon_crosshair(weapon_crosshair_t *weapon);
//          |           |
void set_icemaker_weapon_crosshair(weapon_crosshair_t *weapon_crosshair,
    sfVector2u position);
void set_leg_weapon_crosshair(weapon_crosshair_t *weapon_crosshair,
    sfVector2u position);
void set_secondary_weapon_crosshair(weapon_crosshair_t *weapon_crosshair,
    sfVector2u position);
void set_primary_weapon_crosshair(weapon_crosshair_t *weapon_crosshair,
    sfVector2u position);
//      |       |
#endif /* WEAPON_H */
