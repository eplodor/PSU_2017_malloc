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

SRCS		= list.c \
		  malloc.c \
		  free.c \
		  realloc.c

SRCS2		= tests/prep_structs_tests.c \
		  tests/tests-add_after.c \
		  tests/tests-delete_elem_list.c \
		  tests/tests-best_fit.c \
		  malloc.c \
		  list.c

OBJS2		= $(SRCS2:.c=.o)

CFLAGS		= -g -O3 -W -Wall -Wextra -Wpadded -ansi -pedantic --std=gnu99

all:		$(NAME)

$(NAME):	$(OBJS)
		@$(CC) -shared -fPIC $(SRCS) -o $(NAME)

tests_run:	$(OBJS2)
		@$(CC) $(SRCS2) -o $(NAME2) --coverage -lcriterion
		./tests_malloc

clean:
		@$(RM) $(OBJS)
		@$(RM) $(OBJS2)
		@$(RM) *.gcno
		@$(RM) *.gcda

fclean:		clean
		@$(RM) $(NAME)
		@$(RM) $(NAME2)

re:		fclean all tests_run
