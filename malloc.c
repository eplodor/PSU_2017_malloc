/*
** EPITECH PROJECT, 2017
** PSU_2017_malloc
** File description:
** Functions needed to recode malloc
*/

#include "malloc.h"

int		increase_heap(size_t size)
{
	size_t	size_to_add = PAGE_SIZE;

	while (size_to_add < size)
		size_to_add += PAGE_SIZE;
	if (!head) {
		head = sbrk(size_to_add);
		if (head == FAIL)
			return (1);
		head->start = NULL;
		head->end = NULL;
		head->last_freed = NULL;
		head->mem_left = size_to_add - INFO;
	} else if (head->mem_left < size) {
		if (sbrk(size_to_add) == FAIL)
			return (1);
		head->mem_left += size_to_add;
	}
	return (0);
}

info_t		*best_fit(info_t *start, size_t size)
{
        info_t	*best = NULL;
        info_t	*tmp = start;

        while (tmp) {
                while (tmp && (!tmp->free || tmp->size <= size)) {
                        if (tmp->free && (size - INFO == tmp->size))
                                return (tmp);
                        tmp = tmp->next;
                }
                if (tmp) {
                        if (!best || ((tmp->size - size) < (best->size - size)))
                                best = tmp;
                        tmp = tmp->next;
                }
        }
        return (best);
}

int		split_block(info_t *cur, size_t new_size)
{
	info_t	*new;

	if (cur) {
		if (new_size == cur->size)
			return (0);
		if ((new_size > cur->size) || ((cur->size - new_size) <= INFO))
			return (1);
		new = (info_t *)((char *)(cur + 1) + new_size);
		new->free = FREE;
		new->size = cur->size - new_size - INFO;
		cur->size = new_size;
		add_after(cur, new);
		return (0);
	}
	return (1);
}

/*void		*malloc(size_t size)
{
	size_t	s = ALIGN(size);
	info_t *best;

	if (increase_heap(s + INFO))
		return (NULL);
	/* if (head->last_freed && */
	/*     (head->last_freed->size == s || head->last_freed->size >= s + INFO)) */
	/* 	best = head->last_freed; */
	/* else
	best = best_fit(head->start, s + INFO);
	if (!best){
		if (!head->end)
			best = (info_t *)(head + 1);
		else
			best = (info_t *)((char *)(head->end + 1) + head->end->size);
		best->free = 0;
		best->size = s;
		add_after(head->end, best);
		head->mem_left -= (s + INFO);
	}
	else{
		best->free = 0;
		split_block(best, s);
	}
	return ((void *)(best + 1));
} */
