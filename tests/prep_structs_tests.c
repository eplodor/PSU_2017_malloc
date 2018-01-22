/*
** EPITECH PROJECT, 2018
** prep_structs
** File description:
** prep_structs
*/

#include "../malloc.h"

info_t		*init_struct_info(info_t *_next, info_t *_prev,
				  size_t _size, size_t _free)
{
	info_t	*new = malloc(sizeof(*new));

	if (new) {
		new->next = _next;
		new->prev = _prev;
		new->size = _size;
		new->free = _free;
	}
	return (new);
}

head_t		*init_struct_head(info_t *_start, info_t *_end)
{
	head_t	*head = malloc(sizeof(*head));

	if (head) {
		head->start = _start;
		head->end = _end;
	}
	return (head);
}
