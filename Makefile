##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Makfile
##

SRC_PATH = src/
INIT_PATH = init/
TEST_PATH = tests/
EVENT_PATH = event/
GAME_PATH = game/
IN_GAME_PATH = in_game/
MAP_PATH = map/
ERROR_PATH = error_handling/
MATH_PATH = math/
RAYCAST_PATH = raycast/
PARSING_PATH = parsing/
DEBUG_PATH = debug/
BUTTON_PATH = buttons/
MENU_PATH = menu/
CALL_MENU_PATH = call_menu/
CALL_GAME_PATH = call_game/
CALL_SETTING_PATH = call_setting/
MUSIC_PATH = music/
HUD_PATH = hud_overlay/
SETTING_PATH = setting/

SRC =		$(addprefix $(SRC_PATH), \
				$(addprefix $(BUTTON_PATH), \
					button_status.c \
					create_button.c \
					draw_button.c	\
					init_buttons.c \
					set_button_color.c	\
					set_button_rect.c	\
					set_button_text.c	\
					set_sprite.c	\
					draw_all_buttons.c	\
					free_everything_button.c	\
				)\
				$(addprefix $(SETTING_PATH), \
						setting_screen.c	\
					)\
				$(addprefix $(MENU_PATH), \
					bg_menu_anim.c	\
					menu.c	\
				)\
				$(addprefix $(ERROR_PATH), \
					error_handling.c \
				)\
				$(addprefix $(EVENT_PATH), \
					$(addprefix $(CALL_GAME_PATH), \
						calls_game.c \
						game_scene.c \
						mov_player.c \
					)\
					$(addprefix $(MUSIC_PATH), \
						music.c	\
					)\
					$(addprefix $(CALL_MENU_PATH), \
						calls_menu.c \
					)\
					$(addprefix $(CALL_SETTING_PATH), \
						calls_setting.c \
					)\
					set_fullscreen.c \
					is_keyboard_input.c \
				)\
				$(addprefix $(GAME_PATH), \
					game_loop.c \
					start.c \
					time.c \
				)\
				$(addprefix $(IN_GAME_PATH), \
					draw_background.c \
					draw_weapon.c \
					draw.c \
					draw_sprint_overlay.c \
				)\
				$(addprefix $(INIT_PATH), \
					init_entity.c	\
					init_error_screen.c	\
					init_game.c \
					init_map.c \
					init_menu.c	\
					init_music.c	\
					init_player.c \
					init_scene.c	\
					init_settings.c	\
					init_sys_data.c \
					init_map.c \
					init_setting_screen.c	\
					init_weapon.c \
					init_window.c \
					init_wall_sprites.c	\
				)\
				$(addprefix  $(RAYCAST_PATH), \
					raycasting.c \
				)\
				$(addprefix $(PARSING_PATH), \
					destroy_map.c	\
					map_generator.c	\
					parser.c	\
				)\
				$(addprefix $(DEBUG_PATH), \
					show_map_debug.c	\
				)\
				$(addprefix $(TEST_PATH), \
					$(addprefix $(MAP_PATH), \
						map.c \
					)\
				)\
				$(addprefix $(HUD_PATH), \
					hud_overlay.c	\
				)\
				main.c \
			)

OBJ =		$(SRC:.c=.o)

NAME =		wolf3d

all: mklib $(NAME)

CSFMLFLAGS		=	-lcsfml-system -lcsfml-window	\
					-lcsfml-graphics -lcsfml-audio
CPPFLAGS		+=	-iquote include
CFLAGS			+=	-Wall -Wextra
LDFLAGS			+=	-L ./lib/
LDLIBS			+=	-lmy -lm $(CSFMLFLAGS)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(LDLIBS)

clean:
	make clean -C ./lib/my/
	$(RM) $(OBJ)

fclean:	clean
	make fclean -C ./lib/my/
	$(RM) $(NAME)

re:	fclean all

mklib:
	make -C ./lib/my/

.PHONY: all clean fclean re mklib
