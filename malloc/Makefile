##
## EPITECH PROJECT, 2017
## PSU_2017_malloc
## File description:
## Makefile
##

CC		= gcc

RM		= rm -f

NAME		= libmy_malloc.so

SRCS		= list.c \
		  malloc.c \
		  free.c \
		  realloc.c

OBJS		= $(SRCS:.c=.o)

CFLAGS		= -g -O3 -W -Wall -Wextra -Wpadded -ansi -pedantic --std=gnu99

all:		$(NAME)

$(NAME):	$(OBJS)
		@$(CC) -shared -fPIC $(SRCS) -o $(NAME)

clean:
		@$(RM) $(OBJS)

fclean:		clean
		@$(RM) $(NAME)

re:		fclean all
