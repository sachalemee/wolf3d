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
PARSING_PATH = parsing/
DEBUG_PATH = debug/

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
					init_player.c \
					set_window.c \
				)\
				$(addprefix $(MATH_PATH), \
					degree_to_radian.c \
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
						browse_map.c \
						map.c \
					)\
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
