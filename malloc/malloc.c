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
	if (!head){
		head = sbrk(size_to_add);
		if (head == FAIL)
			return (1);
		head->start = NULL;
		head->end = NULL;
		head->last_freed = NULL;
		head->mem_left = size_to_add - INFO;
	}
	else if (head->mem_left < size){
		if (sbrk(size_to_add) == FAIL)
			return (1);
		head->mem_left += size_to_add;
	}
	return (0);
}

t_info		best_fit(t_info start, size_t size)
{
        t_info	best = NULL;
        t_info	tmp = start;

        while (tmp){
                while (tmp && (!tmp->free || tmp->size <= size)){
                        if (tmp->free && size - INFO == tmp->size)
                                return (tmp);
                        tmp = tmp->next;
                }
                if (tmp){
                        if (!best || ((tmp->size - size) < (best->size - size)))
                                best = tmp;
                        tmp = tmp->next;
                }
        }
        return (best);
}

int		split_block(t_info cur, size_t new_size)
{
	t_info	new;

	if (!cur)
		return (1);
	if (new_size == cur->size)
		return (0);
	if (new_size > cur->size || cur->size - new_size <= INFO)
		return (1);
	new = (t_info)((char *)(cur + 1) + new_size);
	new->free = 1;
	new->size = cur->size - new_size - INFO;
	cur->size = new_size;
	add_after(cur, new);
	return (0);
}

void		*malloc(size_t size)
{
	size_t	s = ALIGN(size);
	t_info	best;

//	write(1, "Malloc\n", 7);
	if (increase_heap(s + INFO))
		return (NULL);
	/* if (head->last_freed && */
	/*     (head->last_freed->size == s || head->last_freed->size >= s + INFO)) */
	/* 	best = head->last_freed; */
	/* else */
	best = best_fit(head->start, s + INFO);
	if (!best){
		if (!head->end)
			best = (t_info)(head + 1);
		else
			best = (t_info)((char *)(head->end + 1) + head->end->size);
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
}
