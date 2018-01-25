/*
** EPITECH PROJECT, 2017
** PSU_2017_malloc
** File description:
** Linked list functions
*/

#include "malloc.h"

void		remove_node(info_t *cur)
{
	if (cur) {
		if (cur == head->start && cur == head->end) {
			head->start = NULL;
			head->end = NULL;
		} else if (cur == head->start) {
			head->start->next->prev = NULL;
			head->start = head->start->next;
		} else if (cur == head->end) {
			head->end->prev->next = NULL;
			head->end = head->end->prev;
		} else {
			cur->prev->next = cur->next;
			cur->next->prev = cur->prev;
		}
	}
}

void		add_after(info_t *cur, info_t *new)
{
	new->next = NULL;
	new->prev = NULL;

	if (!cur) {
		head->start = new;
		head->end = new;
	}
	else {
		if (cur == head->end) {
			new->prev = head->end;
			head->end->next = new;
			head->end = new;
		} else {
			new->prev = cur;
			new->next = cur->next;
			cur->next->prev = new;
			cur->next = new;
		}
	}
}
