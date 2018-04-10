/*
** EPITECH PROJECT, 2018
** increase_heap
** File description:
** increase_heap
*/

#include "malloc.h"

Test(increase_heap, first_call)
{
	cr_expect_eq(increase_heap(67), 0);
	cr_expect_neq(head, NULL);
	cr_expect_eq(head->mem_left, PAGE_SIZE - HEAD);
}

Test(increase_heap, enough_room)
{
	increase_heap(67);
	cr_expect_eq(increase_heap(8), 0);
	cr_expect_eq(head->mem_left, PAGE_SIZE - HEAD);
}

Test(increase_heap, not_enough_room)
{
	increase_heap(67);
	cr_expect_eq(increase_heap(PAGE_SIZE), 0);
	cr_expect_eq((long)head->mem_left, 2*PAGE_SIZE - HEAD);
}
