/*
** EPITECH PROJECT, 2017
** PSU_2017_malloc
** File description:
** Functions needed to recode malloc
*/

#include "malloc.h"

const int		USED = 0;
const void		*FAIL = (void *)-1;
const size_t		HEAD = sizeof(struct head_s);
const size_t		INFO = sizeof(struct info_s);

int			increase_heap(size_t size)
{
	size_t		size_to_add = PAGE_SIZE;

	while (size_to_add < size)
		size_to_add += PAGE_SIZE;
	if (!head) {
		head = sbrk(size_to_add);
		if (head == FAIL)
			return (1);
		memset(head, 0, HEAD);
		head->mem_left = size_to_add - HEAD;
	} else if (head->mem_left < size) {
		if (sbrk(size_to_add) == FAIL)
			return (1);
		head->mem_left += size_to_add;
	}
	return (0);
}

info_t			*best_fit(info_t *start, size_t size)
{
        info_t		*best = NULL;
        info_t		*tmp = start;

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

int			split_block(info_t *cur, size_t new_size)
{
	info_t		*new;

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

info_t			*add_block_end(info_t *best, size_t size)
{
	if (!head->end)
		best = (info_t *)(head + 1);
	else
		best = (info_t *)((char *)(head->end + 1) + head->end->size);
	best->free = USED;
	best->size = size;
	add_after(head->end, best);
	head->mem_left -= (size + INFO);
	return (best);
}

void			*malloc(size_t size)
{
	const size_t	s = ALIGN(size);
	info_t		*best = NULL;

	if (size <= 0)
		return (NULL);
	if (!increase_heap(s + INFO)) {
		best = best_fit(head->start, s + INFO);
		if (!best)
			best = add_block_end(best, s);
		else {
			best->free = USED;
			split_block(best, s);
		}
		return ((void *)(best + 1));
	}
	return (NULL);
}
