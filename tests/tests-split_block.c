/*
** EPITECH PROJECT, 2018
** split_block
** File description:
** split_block
*/

#include "../malloc.h"

Test(split_block, non_existent_block)
{
	int	res = split_block(NULL, 89);

	cr_expect_eq(res, 1);
}

Test(split_block, perfect_fit)
{
	info_t	*a = init_struct_info(89, FREE);
	info_t	*b = init_struct_info(34, FREE);
	set_struct_info_elem(a, NULL, b);
	set_struct_info_elem(b, a, NULL);
	head = init_struct_head(a, b);
	int	res = split_block(a, 89);

	cr_expect_eq(res, 0);
	cr_expect_eq(a->next, b);
	cr_expect_eq(b->prev, a);
	free(a);
	free(b);
	free(head);
}

Test(split_block, not_enough_room1)
{
	info_t	*a = init_struct_info(89, FREE);
	info_t	*b = init_struct_info(34, FREE);
	set_struct_info_elem(a, NULL, b);
	set_struct_info_elem(b, a, NULL);
	head = init_struct_head(a, b);
	int	res = split_block(a, 90);

	cr_expect_eq(res, 1);
	cr_expect_eq(a->next, b);
	cr_expect_eq(b->prev, a);
	free(a);
	free(b);
	free(head);
}

Test(split_block, not_enough_room2)
{
	info_t	*a = init_struct_info(89, FREE);
	info_t	*b = init_struct_info(34, FREE);
	set_struct_info_elem(a, NULL, b);
	set_struct_info_elem(b, a, NULL);
	head = init_struct_head(a, b);
	int	res = split_block(a, 80);

	cr_expect_eq(res, 1);
	cr_expect_eq(a->next, b);
	cr_expect_eq(b->prev, a);
	free(a);
	free(b);
	free(head);
}

Test(split_block, not_enough_room3)
{
	info_t	*a = init_struct_info(89, FREE);
	info_t	*b = init_struct_info(34, FREE);
	set_struct_info_elem(a, NULL, b);
	set_struct_info_elem(b, a, NULL);
	head = init_struct_head(a, b);
	int	res = split_block(a, 89 - INFO);

	cr_expect_eq(res, 1);
	cr_expect_eq(a->next, b);
	cr_expect_eq(b->prev, a);
	free(a);
	free(b);
	free(head);
}

/* Enough_room non testable du à la configuration actuelle des listes chainées avec sbrk
** Cependant, fonction verifiée et fonctionnelle avec un malloc dans la fonction split_block
**
** Test(split_block, enough_room)
** {
**	info_t	*a = init_struct_info(89, FREE);
**	info_t	*b = init_struct_info(34, FREE);
**	set_struct_info_elem(a, NULL, b);
**	set_struct_info_elem(b, a, NULL);
**	head = init_struct_head(a, b);
**	int	res = split_block(a, 2);
**
**	cr_expect_eq(res, 0);
**	cr_expect_neq(a->next, b);
**	cr_expect_neq(b->prev, a);
**	cr_expect_eq(a->next->next, b);
**	cr_expect_eq(b->prev->prev, a);
**	cr_expect_eq(a->next->size, 89 - 2 - INFO);
**	free(a);
**	free(b);
**	free(head); }
*/
