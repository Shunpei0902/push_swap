/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasano <shunkotkg0141@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 04:50:32 by sasano            #+#    #+#             */
/*   Updated: 2024/11/17 04:57:12 by sasano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	stack_size(t_stack *stack)
{
	size_t	size;
	t_node	*node;

	if (!stack || !stack->top)
		return (0);
	size = 0;
	node = stack->top;
	while (1)
	{
		size++;
		node = node->next;
		if (node == stack->top)
			break ;
	}
	return (size);
}

void	move_two_node_to_b(t_stack *a, t_stack *b)
{
	pb(a, b);
	pb(a, b);
}

void	move_stack(t_stack *a, t_stack *b, t_search_result *result)
{
	while (result->a_head_count[0] > 0 && result->b_head_count[0] > 0)
	{
		result->a_head_count[0]--;
		result->b_head_count[0]--;
		rr(a, b, 1);
	}
	while (result->a_head_count[1] > 0 && result->b_head_count[1] > 0)
	{
		result->a_head_count[1]--;
		result->b_head_count[1]--;
		rrr(a, b, 1);
	}
	while (result->a_head_count[0]-- > 0)
		ra(a, 1);
	while (result->a_head_count[1]-- > 0)
		rra(a, 1);
	while (result->b_head_count[0]-- > 0)
		rb(b, 1);
	while (result->b_head_count[1]-- > 0)
		rrb(b, 1);
	pb(a, b);
	free_search_result(result);
}

void	fill_minus(t_search_result *result, int index)
{
	if (index == 0)
	{
		result->a_head_count[1] = -1;
		result->b_head_count[1] = -1;
	}
	else if (index == 1)
	{
		result->a_head_count[1] = -1;
		result->b_head_count[0] = -1;
	}
	else if (index == 2)
	{
		result->a_head_count[0] = -1;
		result->b_head_count[1] = -1;
	}
	else if (index == 3)
	{
		result->a_head_count[0] = -1;
		result->b_head_count[0] = -1;
	}
}

int	com_count(int *count_array)
{
	int	i;
	int	value;
	int	index;

	i = 0;
	value = 0;
	index = 0;
	while (i < 4)
	{
		if (value == 0 || (count_array[i] != 0 && value > count_array[i]))
		{
			value = count_array[i];
			index = i;
		}
		i++;
	}
	return (index);
}
