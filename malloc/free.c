/*
** EPITECH PROJECT, 2017
** PSU_2017_malloc
** File description:
** Functions to recode free
*/

#include "malloc.h"

int		is_valid(void *ptr)
{
	if (!ptr || ptr < (void *)head->start || ptr > (void *)(head->end + 1))
		return (1);
	return (0);
}

t_info		get_info(void *ptr)
{
	return ((t_info)ptr - 1);
}

void		*fuse(t_info start)
{
	if (start && start->next){
		start->size += INFO + start->next->size;
		remove_node(start->next);
	}
	return (start);
}

void		free(void *ptr)
{
	t_info	start;

//	write(1, "Free\n", 5);
	if (!is_valid(ptr) && ((size_t)ptr % 16 == 0)){
//		write(1, "Free\n", 5);
		start = get_info(ptr);
		start->free = 1;
		/* if (start->prev && start->prev->free) */
		/* 	start = fuse(start->prev); */
		/* if (start->next && start->next->free) */
		/* 	start = fuse(start); */
		head->last_freed = start;
	}
	return ;
}
