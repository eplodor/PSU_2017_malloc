/*
** EPITECH PROJECT, 2018
** test-add_elem_after
** File description:
** test-add_elem_after
*/

#include "../malloc.h"

Test(add_after, empty_linked_list)
{
	head_t	*h = init_struct_head(NULL, NULL);
	info_t	*i = init_struct_info(NULL, NULL, 56, 1);

	add_afer(h->start, i);
	cr_assert_eq(h->start, i);
	cr_assert_eq(h->end, i);
	free(i);
	free(h);
}

Test(add_after, one_elem_linked_list)
{
	info_t	*i = init_struct_info(NULL, NULL, 59, 1);
	info_t	*j = init_struct_info(NULL, NULL, 78, 1);
	head_t	*h = init_struct_head(i, i);

	add_after(h->start, j);
	cr_assert_eq(h->end, j);
	cr_assert_eq(h->start->next, h->end);
	cr_assert_eq(h->end->prev, h->start);
	free(i);
	free(j);
	free(h);
}

Test(add_after, add_elem_end)
{
	info_t	*i;
	info_t	*j;
	info_t	*new;
	head_t	*h;

	i = init_struct_info(NULL, j, 78, 1);
	j = init_struct_info(i, NULL, 2, 1);
	new = init_struct_info(NULL, NULL, 56, 1);
	h = init_struct_head(i, j);
	add_after(h->end, new);
	cr_assert_eq(h->end, new);
	cr_assert_eq(j->next, new);
	cr_assert_eq(new->next, NULL);
	cr_assert_eq(h->end->prev, j);
	free(i);
	free(new);
	free(j);
	free(h);
}

Test(add_after, default_case)
{
	info_t	*i;
	info_t	*j;
	info_t	*new;
	head_t	*h;

	i = init_struct_info(NULL, j, 78, 1);
	j = init_struct_info(i, NULL, 2, 1);
	new = init_struct_info(NULL, NULL, 56, 1);
	h = init_struct_head(i, j);
	add_after(i, new);
	cr_assert_eq(i->next, new);
	cr_assert_eq(new->prev, i);
	cr_assert_eq(new->next, h->end);
	cr_assert_eq(h->end->prev, new);
	free(i);
	free(new);
	free(j);
	free(h);
}
