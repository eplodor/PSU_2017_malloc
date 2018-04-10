/*
** EPITECH PROJECT, 2018
** PSU_2017_malloc
** File description:
** calloc
*/

#include "malloc.h"

void			*calloc(size_t nmemb, size_t size)
{
	const size_t	s = nmemb * size;
	void		*ptr = malloc(s);

	if (ptr)
		memset(ptr, 0, s);
	return (ptr);
}
