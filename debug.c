/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasano <shunkotkg0141@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 01:03:00 by sasano            #+#    #+#             */
/*   Updated: 2024/11/17 05:05:38 by sasano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *a, t_stack *b)
{
	t_node	*node;

	ft_printf("a: ");
	if (!a || !a->top)
		ft_printf("NULL\n");
	else
	{
		node = a->top;
		while (1)
		{
			ft_printf("%d ", node->value);
			node = node->next;
			if (node == a->top)
				break ;
		}
		ft_printf("\n");
	}
	ft_printf("b: ");
	if (!b || !b->top)
		ft_printf("NULL\n");
	else
	{
		node = b->top;
		while (1)
		{
			ft_printf("%d ", node->value);
			node = node->next;
			if (node == b->top)
				break ;
		}
		ft_printf("\n");
	}
}

void	print_argv(int i, char **str)
{
	while (i--)
	{
		ft_printf("<%s> ", *(str++));
	}
	ft_printf("\n");
}
