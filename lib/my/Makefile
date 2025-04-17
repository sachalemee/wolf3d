##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile for my_hunter
##

BIN =   ../libmy.a

SRC =				malloc_checker.c	\
					my_dputstr.c	\
					my_qsort_r.c	\
					my_strconcat.c	\
					my_strcpy.c	\
					my_strlen.c	\
					my_destroy_array.c	\
					linked_lists/fifo_lifo_lists.c	\
					linked_lists/linked_lists.c

OBJ				=	$(SRC:.c=.o)

CC				?=	gcc

RM				?=	rm -rf

HEADERS			=	my.h	\
					linked_lists.h	\
					my_qsort_r.h

CPPFLAGS		+=	-iquote ./include/
CFLAGS			+=	-Wall -Wextra
LDFLAGS			+=	-L ./lib/
LDLIBS			+=	-lmy

all: $(BIN)

$(BIN): $(OBJ)
	cp $(HEADERS) ../../include/
	ar rc $(BIN) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(BIN)

re: fclean all

.PHONY: clean fclean all re
