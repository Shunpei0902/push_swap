/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasano <shunkotkg0141@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 22:54:23 by sasano            #+#    #+#             */
/*   Updated: 2024/11/17 05:19:34 by sasano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	handle_top_mid_bot(t_stack *a, int top, int mid, int bot)
{
	if (top > mid && top < bot)
		sa(a, 1);
	else if (top < mid && top > bot)
		rra(a, 1);
	else if (top > mid && mid > bot)
	{
		sa(a, 1);
		rra(a, 1);
	}
	else if (top > mid && mid < bot)
		ra(a, 1);
	else if (top < mid && mid > bot)
	{
		sa(a, 1);
		ra(a, 1);
	}
}

int	sort_three_element(t_stack *a)
{
	int	top;
	int	mid;
	int	bot;

	if (stack_size(a) != 3)
		return (0);
	top = a->top->value;
	mid = a->top->next->value;
	bot = a->top->prev->value;
	if (top < mid && mid < bot)
		return (1);
	handle_top_mid_bot(a, top, mid, bot);
	return (1);
}

int	sort_two_element(t_stack *a)
{
	if (stack_size(a) != 2)
		return (0);
	if (a->top->value > a->top->next->value)
		sa(a, 1);
	return (1);
}

int	search_on_inserted_a_count(int value, t_stack *a)
{
	int		count;
	t_node	*node;

	count = 0;
	node = a->top;
	while (1)
	{
		if (((node->value > value || node->prev->value < value)
				&& node->prev->value > node->value) || (node->value > value
				&& node->prev->value < value))
			return (count);
		node = node->next;
		if (node == a->top)
			break ;
		count++;
	}
	return (count);
}

void	rotate_sort_a(t_stack *a)
{
	t_node	*node;
	int		size;
	int		count;

	size = stack_size(a);
	count = 0;
	node = a->top;
	while (node->value != 0 && count++ < size)
		node = node->next;
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
