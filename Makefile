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
RAYCAST_PATH = raycast/

SRC =		$(addprefix $(SRC_PATH), \
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
					init_game.c \
					init_info.c \
					init_map.c \
					init_player.c \
					set_window.c \
				)\
				$(addprefix  $(RAYCAST_PATH), \
					raycasting.c \
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
