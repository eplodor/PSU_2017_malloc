/*
** EPITECH PROJECT, 2018
** best_fit
** File description:
** best_fit
*/

#include "malloc.h"

Test(best_fit, empty_list)
{
	info_t	*best;

	best = best_fit(NULL, 90 + INFO);
	cr_expect_eq(best, NULL);
}

Test(best_fit, one_elem_and_not_matching)
{
	info_t	*a = init_struct_info(56, USED);
	head = init_struct_head(a, a);
	info_t	*best = best_fit(head->start, 56 + INFO);

	cr_expect_eq(best, NULL);
	free(a);
	free(head);
}

Test(best_fit, one_elem_and_matching)
{
	info_t	*a = init_struct_info(106, FREE);
	head = init_struct_head(a, a);
	info_t	*best = best_fit(head->start, 54 + INFO);

	cr_expect_eq(best, a);
	free(a);
	free(head);
}

Test(best_fit, matching_chunk_middle)
{
	info_t	*a, *b, *c, *best;

	a = init_struct_info(89, USED);
	b = init_struct_info(197, FREE);
	c = init_struct_info(4, USED);
	set_struct_info_elem(a, NULL, b);
	set_struct_info_elem(b, a, c);
	set_struct_info_elem(c, b, NULL);
	head = init_struct_head(a, c);
	best = best_fit(head->start, 89 + INFO);
	cr_expect_eq(best, b);
	free(a);
	free(b);
	free(c);
	free(head);
}

Test(best_fit, wide_enough_but_used)
{
	info_t	*a, *b, *c, *best;

	a = init_struct_info(89, USED);
	b = init_struct_info(111, USED);
	c = init_struct_info(4, USED);
	set_struct_info_elem(a, NULL, b);
	set_struct_info_elem(b, a, c);
	set_struct_info_elem(c, b, NULL);
	head = init_struct_head(a, c);
	best = best_fit(head->start, 2 + INFO);
	cr_expect_eq(best, NULL);
	free(a);
	free(b);
	free(c);
	free(head);
}

Test(best_fit, free_but_too_small)
{
	info_t	*a, *b, *c, *best;

	a = init_struct_info(89, FREE);
	b = init_struct_info(111, FREE);
	c = init_struct_info(4, FREE);
	set_struct_info_elem(a, NULL, b);
	set_struct_info_elem(b, a, c);
	set_struct_info_elem(c, b, NULL);
	head = init_struct_head(a, c);
	best = best_fit(head->start, 201 + INFO);
	cr_expect_eq(best, NULL);
	free(a);
	free(b);
	free(c);
	free(head);
}

Test(best_fit, fit_at_the_very_end)
{
	info_t	*a, *b, *c, *best;

	a = init_struct_info(89, USED);
	b = init_struct_info(111, USED);
	c = init_struct_info(4, FREE);
	set_struct_info_elem(a, NULL, b);
	set_struct_info_elem(b, a, c);
	set_struct_info_elem(c, b, NULL);
	head = init_struct_head(a, c);
	best = best_fit(head->start, 4 + INFO);
	cr_expect_eq(best, c);
	free(a);
	free(b);
	free(c);
	free(head);
}

Test(best_fit, fit_at_the_very_beggining)
{
	info_t	*a, *b, *c, *best;

	a = init_struct_info(89, FREE);
	b = init_struct_info(111, USED);
	c = init_struct_info(4, USED);
	set_struct_info_elem(a, NULL, b);
	set_struct_info_elem(b, a, c);
	set_struct_info_elem(c, b, NULL);
	head = init_struct_head(a, c);
	best = best_fit(head->start, 89 + INFO);
	cr_expect_eq(best, a);
	free(a);
	free(b);
	free(c);
	free(head);
}

Test(best_fit, perfect_fit_middle_list)
{
	info_t	*a, *b, *c, *best;

	a = init_struct_info(89, USED);
	b = init_struct_info(111, FREE);
	c = init_struct_info(4, USED);
	set_struct_info_elem(a, NULL, b);
	set_struct_info_elem(b, a, c);
	set_struct_info_elem(c, b, NULL);
	head = init_struct_head(a, c);
	best = best_fit(head->start, 111 + INFO);
	cr_expect_eq(best, b);
	free(a);
	free(b);
	free(c);
	free(head);
}
