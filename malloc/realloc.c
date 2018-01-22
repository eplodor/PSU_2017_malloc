/*
** EPITECH PROJECT, 2017
** PSU_2017_malloc
** File description:
** Show_alloc_mem & Realloc
*/


#include "malloc.h"

void		show_alloc_mem(void)
{
	t_info	i;
	char	*tmp;

	i = head->start;
	if (!head->end){
		printf("break : %p\n", sbrk(0));
		return ;
	}
	printf("break : %p\n", get_current_break());
	while (i){
		tmp = (char *)(i + 1) + i->size;
		printf("%p - %p : %ld bytes\n", (void *)(i + 1), tmp, i->size);
		i = i->next;
	}
}

void            *realloc(void *oldptr, size_t size)
{
	void	*newptr;
	size_t	s = ALIGN(size);
	t_info	info;

//	write(1, "Realloc\n", 8);
	if (!oldptr)
		return (malloc(s));
	if (is_valid(oldptr))
		return (NULL);
	info = get_info(oldptr);
	if (info->free){
		if (!size)
			return (oldptr);
		return (malloc(s));
	}
	if (!size){
		free(oldptr);
		return (oldptr);
	}
	info = fuse(info);
	if (split_block(info, s))
		return (oldptr);
	if (!(newptr = malloc(s)))
		return (NULL);
	memcpy(newptr, oldptr, s);
	free(oldptr);
	return (newptr);
}
