/*
** EPITECH PROJECT, 2017
** PSU_2017_malloc
** File description:
** Header malloc
*/

#ifndef MALLOC_H_
# define MALLOC_H_

	#include <criterion/criterion.h>
	#include <unistd.h>
	#include <stdio.h>
	#include <stdlib.h>
	#include <signal.h>
	#include <string.h>
	#include <inttypes.h>
	#include <limits.h>

	#ifndef __X86_64__
	#define ALIGN(x) (((((x) - 1) >> 4) << 4) + 16)
	#else
	#define ALIGN(x) (((((x) - 1) >> 3) << 3) + 8)
	#endif

	#define PAGE_SIZE sysconf(_SC_PAGESIZE)

typedef struct		info_s
{
	struct info_s	*next;
	struct info_s	*prev;
	size_t		size;
	size_t		free;
}			info_t;

typedef struct		head_s
{
	struct info_s	*start;
	struct info_s	*end;
	size_t		mem_left;
}			head_t;

head_t			*head;
extern const size_t	INFO;
extern const size_t	HEAD;
extern const void	*FAIL;
extern const int	USED;
extern const int	FREE;

void			remove_node(info_t *);
void			add_after(info_t *, info_t *);

info_t			*init_struct_info(size_t, size_t);
void			set_struct_info_elem(info_t *, info_t *, info_t *);
head_t			*init_struct_head(info_t *, info_t *);

int			increase_heap(size_t);
info_t			*best_fit(info_t *, size_t);
int			split_block(info_t *, size_t);

int			is_valid(void *);
void			*get_current_break();
info_t			*get_info(void *);
info_t			*fuse(info_t *);

#endif
