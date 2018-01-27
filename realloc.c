/*
** EPITECH PROJECT, 2017
** PSU_2017_malloc
** File description:
** Show_alloc_mem & Realloc
*/


#include "malloc.h"

void		show_alloc_mem(void)
{
	info_t	*i;
	char	*tmp;

	i = head->start;
	if (!head->end) {
		printf("break : %p\n", sbrk(0));
		return ;
	}
	printf("break : %p\n", get_current_break());
	while (i) {
		tmp = (char *)(i + 1) + i->size;
		printf("%p - %p : %ld bytes\n", (void *)(i + 1), tmp, i->size);
		i = i->next;
	}
}

void            *realloc(void *oldptr, size_t size)
{
	/* Oldptr NULL ou free et size != 0, malloc
	   Oldptr NULL ou free et size == 0, return NULL
	   Oldptr non-NULL et free et size != 0, malloc
	   Oldptr non-NUll et free et size == 0, return NULL
	   Oldptr non-NULL et alloué et size == 0, free
	   Oldptr non-NULL et alloué et size > oldptr->size, malloc newptr, memcpy ancien vers nouveau puis free ancien
	   Oldptr non-NULL et alloué et size < oldptr->size, split_block. Si échoue et que suivant free et que somme des tailles a assez de place, fuse. Sinon, effectue cas du dessus
	*/
	info_t	*info;
	void	*newptr;
	size = ALIGN(size);

	if (oldptr)
		info = get_info(oldptr);
	if (!oldptr || info->free) {
		if (size)
			return (malloc(size));
		return (NULL);
	}
	if (!size) {
		free(oldptr);
		return (NULL);
	}
	if (!split_block(info, size))
		return (oldptr);
	newptr = malloc(size);
	if (!newptr)
		return (NULL);
	memcpy(newptr, oldptr, size);
	free(oldptr);
	return (newptr);
}
