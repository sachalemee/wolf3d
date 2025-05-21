/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-marin.jeunot
** File description:
** buttons
*/

#ifndef BUTTONS_H_
    #define BUTTONS_H_
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #define SUCCESS 0
    #define NB_BUTTONS_MENU 3
    #define NB_BUTTONS_SETTINGS 4
    #define NB_COLOR 5
    #define B_TEXTURE "ressources/Wolf3D_OGG/texture/texture_bouton.png"
    #define FONT "ressources/Wolf3D_OGG/font/font.ttf"
    #define UNUSED(var) (void)(var)

typedef struct buttons_s buttons_t;
typedef struct entity_s entity_t;
typedef struct custom_settings_s custom_settings_t;
typedef struct sys_data_s sys_data_t;
typedef struct musics_s musics_t;
typedef struct game_s game_t;
typedef struct menu_s menu_t;
typedef struct time_info_s time_info_t;
typedef struct setting_screen_s setting_screen_t;


/* enum button color */
typedef enum stat_button_s {
    B_DEFAULT,
    B_HOVER,
    B_PRESSED,
    B_DISABLE,
    B_BLACK
} stat_button_t;

typedef struct buttons_s {
    sfRectangleShape *rect;
    sfVector2f size;
    sfVector2f pos;
    sfText *title;
    sfTexture *texture;
    sfSprite *sprite;
    sfFont *font;
    sfColor color[NB_COLOR];
    sfVector2f scale;
    void (*function)(sys_data_t *);
} buttons_t;

/* buttons functions */
void set_button_text(buttons_t *button,
    char *title, sfFloatRect bounds, sfVector2f origin);

void set_button_color(buttons_t *button);

void set_sprite(buttons_t *button,
    sfFloatRect bounds, sfVector2f origin, char *path);

void set_button_rect(buttons_t *button,
    sfVector2f size, sfVector2f pos);

buttons_t *create_button(sfVector2f pos,
    sfVector2f size, char *title, char *path);

int init_buttons(buttons_t ***buttons);
void destroy_buttons(buttons_t **buttons);

int draw_button(sfRenderWindow *window,
    buttons_t *button);

int buttons_status(sfRenderWindow *window,
    buttons_t *button, sfEvent event, sys_data_t *sys);

void draw_menu_buttons(menu_t *menu, sfRenderWindow *window);
void draw_setting_buttons(setting_screen_t *setting, sfRenderWindow *window);
void free_button(buttons_t *buttons);

#endif /* !BUTTONS_H_ */
