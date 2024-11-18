/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasano <shunkotkg0141@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 05:10:24 by sasano            #+#    #+#             */
/*   Updated: 2024/11/18 14:34:59 by sasano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	handle_insertion(t_stack *a, t_stack *b)
{
	int	size;
	int	count;

	size = stack_size(a);
	count = search_on_inserted_a_count(b->top->value, a);
	if (count <= size / 2)
	{
		while (count-- > 0)
			ra(a, 1);
	}
	else
	{
		while (count++ < size)
			rra(a, 1);
	}
}

void	return_stack_to_a_from_b(t_stack *a, t_stack *b)
{
	while (b->top)
	{
		if ((a->top->value > b->top->value
				&& a->top->prev->value < b->top->value)
			|| ((a->top->prev->value < b->top->value
					|| a->top->value > b->top->value)
				&& a->top->value < a->top->prev->value))
			pa(a, b);
		else
			handle_insertion(a, b);
	}
}

void	rrr(t_stack *a, t_stack *b, int flag)
{
	rra(a, 0);
	rrb(b, 0);
	if (flag)
		ft_putstr_fd("rrr\n", 1);
}
