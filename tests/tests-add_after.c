/*
** EPITECH PROJECT, 2018
** test-add_elem_after
** File description:
** test-add_elem_after
*/

#include "../malloc.h"

Test(add_after, empty_linked_list)
{
	head = init_struct_head(NULL, NULL);
	info_t	*i = init_struct_info(56, 1);

	add_after(head->start, i);
	cr_expect_eq(head->start, i);
	cr_expect_eq(head->end, i);
	free(i);
	free(head);
}

Test(add_after, one_elem_linked_list)
{
	info_t	*i = init_struct_info(59, 1);
	info_t	*new = init_struct_info(78, 1);
	head = init_struct_head(i, i);

	add_after(head->start, new);
	cr_expect_eq(head->end, new);
	cr_expect_eq(head->start->next, head->end);
	cr_expect_eq(head->end->prev, head->start);
	free(i);
	free(new);
	free(head);
}

Test(add_after, add_elem_end)
{
	info_t	*i;
	info_t	*j;
	info_t	*new;

	i = init_struct_info(78, 1);
	j = init_struct_info(2, 1);
	set_struct_info_elem(i, NULL, j);
	set_struct_info_elem(j, j, NULL);
	new = init_struct_info(56, 1);
	head = init_struct_head(i, j);
	add_after(head->end, new);
	cr_expect_eq(head->end, new);
	cr_expect_eq(j->next, new);
	cr_expect_eq(new->next, NULL);
	cr_expect_eq(head->end->prev, j);
	free(i);
	free(new);
	free(j);
	free(head);
}

Test(add_after, default_case)
{
	info_t	*i;
	info_t	*j;
	info_t	*new;

	i = init_struct_info(78, 1);
	j = init_struct_info(2, 1);
	set_struct_info_elem(i, NULL, j);
	set_struct_info_elem(j, j, NULL);
	new = init_struct_info(56, 1);
	head = init_struct_head(i, j);
	add_after(i, new);
	cr_expect_eq(i->next, new);
	cr_expect_eq(new->prev, i);
	cr_expect_eq(new->next, head->end);
	cr_expect_eq(head->end->prev, new);
	free(i);
	free(new);
	free(j);
	free(head);
}
