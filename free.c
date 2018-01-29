/*
** EPITECH PROJECT, 2017
** PSU_2017_malloc
** File description:
** Functions to recode free
*/

#include "malloc.h"


void		*get_current_break()
{
	return (((char *)(head->end + 1)) + head->end->size);
}

int		is_valid(void *ptr)
{
	return ((head->start && ptr < (void *)(head->start + 1)) ||
		(head->end && ptr > get_current_break()));
}


info_t		*get_info(void *ptr)
{
	return ((info_t *)ptr - 1);
}

info_t		*fuse(info_t *start)
{
	if (start && start->next) {
		start->size += INFO + start->next->size;
		remove_node(start->next);
	}
	return (start);
}

void		free(void *ptr)
{
	info_t	*start;

	if (ptr && !is_valid(ptr)) {
		start = get_info(ptr);
		start->free = FREE;
		if (start->prev && start->prev->free)
			start = fuse(start->prev);
		if (start->next && start->next->free)
			start = fuse(start);
		head->last_freed = start;
	}
}
