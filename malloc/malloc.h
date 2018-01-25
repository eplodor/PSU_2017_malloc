/*
** EPITECH PROJECT, 2017
** PSU_2017_malloc
** File description:
** Header malloc
*/

#ifndef MALLOC_H_
# define MALLOC_H_

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <inttypes.h>
#include <limits.h>

# ifndef __X86_64__
#  define ALIGN(x) (((((x) - 1) >> 4) << 4) + 16)
#  else
#  define ALIGN(x) (((((x) - 1) >> 3) << 3) + 8)
# endif

# define PAGE_SIZE sysconf(_SC_PAGESIZE)
# define INFO sizeof(struct s_info)
# define FAIL (void *)-1
# define USED 0
# define FREE 1

typedef struct		s_head
{
	struct s_info	*start;
	struct s_info	*end;
	struct s_info	*last_freed;
	size_t		mem_left;
}			*t_head;

typedef struct		s_info
{
	struct s_info	*next;
	struct s_info	*prev;
	size_t		size;
	size_t		free;
}			*t_info;

t_head			head;

void			remove_node(t_info);
void			add_after(t_info, t_info);

int			split_block(t_info, size_t);

int			is_valid(void *);
void			*get_current_break(void);
t_info			get_info(void *);
void			*fuse(t_info);

#endif
