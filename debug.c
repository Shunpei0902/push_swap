/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasano <shunkotkg0141@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 01:03:00 by sasano            #+#    #+#             */
/*   Updated: 2024/09/17 23:58:24 by sasano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *a, t_stack *b)
{
	t_node	*node;

	printf("a: ");
	if (!a || !a->top)
		printf("NULL\n");
	else
	{
		node = a->top;
		while (1)
		{
			printf("%d ", node->value);
			node = node->next;
			if (node == a->top)
				break;
		}
		printf("\n");
	}
	printf("b: ");
	if (!b || !b->top)
		printf("NULL\n");
	else
	{
		node = b->top;
		while (1)
		{
			printf("%d ", node->value);
			node = node->next;
			if (node == b->top)
				break;
		}
		printf("\n");
	}
}

void print_argv(int i, char **str)
{
	// int i;

	// i = 0;
	while(i--)
	{
		printf("<%s> ", *(str++));
	}
	printf("\n");
}
