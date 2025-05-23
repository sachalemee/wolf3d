##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile for my_hunter
##

BIN =   ../libmy.a

SRC =				malloc_checker.c	\
					my_destroy_array.c	\
					my_dputstr.c	\
					my_fstrsplit.c	\
					my_qsort_r.c	\
					my_strconcat.c	\
					my_strcpy.c	\
					my_strlen.c	\
					my_swap.c	\
					my_swap_char.c	\
					my_str_to_word_array.c	\
					my_uuid_generator.c	\
					str_checks.c	\
					read_file_ctts.c	\
					linked_lists/fifo_lifo_lists.c	\
					linked_lists/linked_lists.c	\
					linked_lists/list_search/deleting.c	\
					linked_lists/list_search/inserting.c	\
					linked_lists/list_search/popping.c	\
					linked_lists/list_search/reading.c

OBJ				=	$(SRC:.c=.o)

CC				?=	gcc

RM				?=	rm -rf

HEADERS			=	my.h	\
					linked_lists.h	\
					my_qsort_r.h

CPPFLAGS		+=	-iquote .
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

debug: CFLAGS += -g3
debug: re

.PHONY: clean fclean all re debug
