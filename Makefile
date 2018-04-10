##
## EPITECH PROJECT, 2017
## PSU_2017_malloc
## File description:
## Makefile
##

CC		= gcc

RM		= rm -f

NAME		= libmy_malloc.so

NAME2		= tests_malloc

SRCS		= src/list.c \
		  src/malloc.c \
		  src/free.c \
		  src/realloc.c \
		  src/calloc.c


SRCS2		= tests/prep_structs_tests.c \
		  tests/tests-add_after.c \
		  tests/tests-delete_elem_list.c \
		  tests/tests-best_fit.c \
		  tests/tests-split_block.c \
		  tests/tests-increase_heap.c \
		  $(SRCS)

OBJS		= $(SRCS:.c=.o)

OBJS2		= $(SRCS2:.c=.o)

CFLAGS		= -W -Wall -Wextra -Iinclude -shared -fPIC

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(CFLAGS) $(SRCS) -o $(NAME)


tests_run:	$(OBJS2)
		@$(CC) -Iinclude $(SRCS2) -o $(NAME2) --coverage -lcriterion
		./tests_malloc

clean:
		@$(RM) $(OBJS)
		@$(RM) $(OBJS2)
		@$(RM) *.gcno
		@$(RM) *.gcda
		@$(RM) *.gcov

fclean:		clean
		@$(RM) $(NAME)
		@$(RM) $(NAME2)

re:		fclean all
