/*
** EPITECH PROJECT, 2018
** tests-remove_node
** File description:
** tests-remove_node
*/

#include "../malloc.h"


Test(remove_node, empty_linked_list)
{
	head_t	*h = init_struct_head(NULL, NULL);

	remove_node(h->start);
	cr_assert_eq(h, NULL);
	free(h);
}

Test(remove_node, one_elem_linked_list)
{
	info_t	*a = init_struct_info(NULL, NULL, 90, 1);
	head_t	*h = init_struct_head(a, a);

	remove_node(a);
	cr_assert_eq(a, NULL);
	cr_assert_eq(h->start, NULL);
	cr_assert_es(h->end, NULL);
	free(h);
}

Test(remove_node, delete_first_elem)
{
	info_t	*a = NULL;
	info_t	*b = NULL;
	info_t	*c = NULL;
	head_t	*h = NULL;

	a = init_struct_info(b, NULL, 89, 1);
	b = init_struct_info(c, a, 67, 1);
	c = init_struct_info(NULL, b, 2, 1);
	h = init_struct_head(a, c);
	remove_node(a);
	cr_assert_eq(a, NULL);
	cr_assert_eq(h->start, b);
	cr_assert_eq(h->start->prev, NULL);
	free(b);
	free(c);
	free(h);
}

Test(remove_node, delete_last_elem)
{
	info_t	*a = NULL;
	info_t	*b = NULL;
	info_t	*c = NULL;
	head_t	*h = NULL;

	a = init_struct_info(b, NULL, 89, 1);
	b = init_struct_info(c, a, 67, 1);
	c = init_struct_info(NULL, b, 2, 1);
	h = init_struct_head(a, c);
	remove_node(c);
	cr_assert_eq(c, NULL);
	cr_assert_eq(b->next, NULL);
	cr_assert_eq(h->end, b);
	free(a);
	free(c);
	free(h);
}

Test(remove_node, default_case)
{
	info_t	*a = NULL;
	info_t	*b = NULL;
	info_t	*c = NULL;
	head_t	*h = NULL;

	a = init_struct_info(b, NULL, 89, 1);
	b = init_struct_info(c, a, 67, 1);
	c = init_struct_info(NULL, b, 2, 1);
	h = init_struct_head(a, c);
	remove_node(b);
	cr_assert_eq(b, NULL);
	cr_assert_eq(h->start, a);
	cr_assert_eq(h->start->next, c);
	cr_assert_eq(c->prev, NULL);
	free(a);
	free(c);
	free(h);
}
