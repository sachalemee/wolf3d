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
DESTROY_PATH = destroy/
MAP_PATH = map/
ERROR_PATH = error_handling/
MATH_PATH = math/
BUTTON_PATH = buttons/
MENU_PATH = menu/

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
				$(addprefix $(MENU_PATH), \
					bg_menu_anim.c	\
					menu.c	\
				)\
				$(addprefix $(DESTROY_PATH), \
					destroy_all.c \
				)\
				$(addprefix $(ERROR_PATH), \
					error_handling.c \
				)\
				$(addprefix $(EVENT_PATH), \
					event_loop.c \
					mov_player.c \
				)\
				$(addprefix $(GAME_PATH), \
					game_loop.c \
					start.c \
				)\
				$(addprefix $(IN_GAME_PATH), \
					draw_background.c \
					draw.c \
				)\
				$(addprefix $(INIT_PATH), \
					init_menu.c	\
					init_game.c \
					init_player.c \
					set_window.c \
				)\
				$(addprefix $(MATH_PATH), \
					degree_to_radian.c \
				)\
				$(addprefix $(TEST_PATH), \
					$(addprefix $(MAP_PATH), \
						browse_map.c \
						map.c \
					)\
				)\
				main.c \
			)

OBJ =		$(SRC:.c=.o)

NAME =		wolf3d

all:		$(NAME)

CFLAGS +=	-Wall -Wextra -g3

CPPFLAGS =	-iquoteinclude -iquotelib

LIBFLAGS = 	-Llib

LIB = 	-Lmy

CSFMLFLAG = -lcsfml-system -lcsfml-window -lcsfml-graphics -lcsfml-audio -lm

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIB) $(LIBFLAGS) $(CSFMLFLAG)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
