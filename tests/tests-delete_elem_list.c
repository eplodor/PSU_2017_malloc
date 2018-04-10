/*
** EPITECH PROJECT, 2018
** tests-remove_node
** File description:
** tests-remove_node
*/

#include "malloc.h"


Test(remove_node, empty_linked_list)
{
	head_t	*h = init_struct_head(NULL, NULL);

	remove_node(h->start);
	cr_expect_eq(h->start, NULL);
	free(h);
}

Test(remove_node, one_elem_linked_list)
{
	info_t	*a = init_struct_info(90, FREE);
	head_t	*h = init_struct_head(a, a);

	remove_node(a);
	cr_expect_eq(h->start, NULL);
	cr_expect_eq(h->end, NULL);
	free(h);
}

Test(remove_node, delete_first_elem)
{
	info_t	*a, *b, *c;
	head_t	*h;

	a = init_struct_info(89, FREE);
	b = init_struct_info(67, FREE);
	c = init_struct_info(2, FREE);
	set_struct_info_elem(a, NULL, b);
	set_struct_info_elem(b, a, c);
	set_struct_info_elem(c, b, NULL);
	h = init_struct_head(a, c);
	remove_node(a);
	cr_expect_eq(h->start, b);
	cr_expect_eq(h->start->prev, NULL);
	free(b);
	free(c);
	free(h);
}

Test(remove_node, delete_last_elem)
{
	info_t	*a, *b, *c;
	head_t	*h;

	a = init_struct_info(89, FREE);
	b = init_struct_info(67, FREE);
	c = init_struct_info(2, FREE);
	set_struct_info_elem(a, NULL, b);
	set_struct_info_elem(b, a, c);
	set_struct_info_elem(c, b, NULL);
	h = init_struct_head(a, c);
	remove_node(c);
	cr_expect_eq(b->next, NULL);
	cr_expect_eq(h->end, b);
	free(a);
	free(c);
	free(h);
}

Test(remove_node, default_case)
{
	info_t	*a, *b, *c;
	head_t	*h;

	a = init_struct_info(89, FREE);
	b = init_struct_info(67, FREE);
	c = init_struct_info(2, FREE);
	set_struct_info_elem(a, NULL, b);
	set_struct_info_elem(b, a, c);
	set_struct_info_elem(c, b, NULL);
	h = init_struct_head(a, c);
	remove_node(b);
	cr_expect_eq(h->start, a);
	cr_expect_eq(h->start->next, c);
	cr_expect_eq(c->prev, a);
	free(a);
	free(c);
	free(h);
}
