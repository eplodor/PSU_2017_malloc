/*
** EPITECH PROJECT, 2018
** prep_structs
** File description:
** prep_structs
*/

#include "../malloc.h"

info_t		*init_struct_info(size_t _size, size_t _free)
{
	info_t	*new = malloc(sizeof(*new));

	if (new) {
		new->next = NULL;
		new->prev = NULL;
		new->size = _size;
		new->free = _free;
	}
	return (new);
}

void		set_struct_info_elem(info_t *cur, info_t *_prev, info_t *_next)
{
	if (cur) {
		cur->prev = _prev;
		cur->next = _next;
	}
}

head_t		*init_struct_head(info_t *_start, info_t *_end)
{
	head = malloc(sizeof(*head));

	if (head) {
		head->start = _start;
		head->end = _end;
	}
	return (head);
}
