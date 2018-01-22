/*
** EPITECH PROJECT, 2018
** Malloc
** File description:
** Malloc
*/

#ifndef MALLOC_H_
# define MALLOC_H_

# include <criterion/criterion.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <string.h>
# include <inttypes.h>
# include <limits.h>

# ifndef __X86_64__
#  define ALIGN(x) (((((x) - 1) >> 4) << 4) + 16)
#  else
#  define ALIGN(x) (((((x) - 1) >> 3) << 3) + 8)
# endif

# define PAGE_SIZE sysconf(_SC_PAGESIZE)
# define INFO sizeof(struct info_s)
# define FAIL (void *)-1

typedef struct          head_s
{
 	struct info_s   *start;
        struct info_s   *end;
	struct info_s   *last_freed;
	size_t          mem_left;
}                       head_t;

typedef struct          info_s
{
 	struct info_s   *next;
	struct info_s   *prev;
	size_t          size;
	size_t          free;
}			info_t;

head_t		*head;
info_t		*init_struct_info(info_t *, info_t *, size_t, size_t);
head_t		*init_struct_head(info_t *, info_t *);

#endif
