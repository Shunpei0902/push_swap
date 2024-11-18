/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_insert_min_node_utils.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasano <shunkotkg0141@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 04:56:33 by sasano            #+#    #+#             */
/*   Updated: 2024/11/18 14:28:15 by sasano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_search_result	*eval_min_count(int *count_array, t_search_result *result,
		t_search_result *min_result)
{
	int	min_count_index;

	min_count_index = com_count(count_array);
	fill_minus(result, min_count_index);
	result->min_count = count_array[min_count_index];
	if (!min_result || (min_result->min_count > result->min_count
			&& result->min_count != 0))
	{
		if (min_result)
			free_search_result(min_result);
		min_result = result;
	}
	else
		free_search_result(result);
	return (min_result);
}

int	check_rest_count(t_search_result *result, t_search_result *min_result)
{
	int	count;

	if (!min_result)
		return (-1);
	count = min_result->min_count;
	if (result->a_head_count[0] != -1 && result->a_head_count[1] != -1)
	{
		if (result->a_head_count[0] < result->a_head_count[1])
			count -= result->a_head_count[0];
		else
			count -= result->a_head_count[1];
	}
	else if (result->a_head_count[0] != -1)
		count -= result->a_head_count[0];
	else if (result->a_head_count[1] != -1)
		count -= result->a_head_count[1];
	return (count);
}

t_node	*search_on_inserted_b_node(int value, t_stack *b)
{
	t_node	*node;

	node = b->top;
	while (1)
	{
		if (((node->value < value || node->prev->value > value)
				&& node->prev->value < node->value) || (node->value < value
				&& node->prev->value > value))
			return (node);
		node = node->next;
		if (node == b->top)
			break ;
	}
	return (node);
}

void	search_insert_position_count(t_stack *stack, t_node *target, int *count,
		int min_count)
{
	int flag;
	t_node *tmp;

	flag = 0;
	tmp = target;
	while (count[0] != -1 || count[1] != -1)
	{
		if (tmp == stack->top)
			break ;
		if (min_count != -1 && min_count <= count[0] && flag == 0)
		{
			count[0] = -1;
			tmp = target;
			flag = 1;
		}
		else if (flag == 0 && count[0]++ != -1)
			tmp = tmp->prev;
		if (min_count != -1 && min_count <= count[1] && flag == 1)
			count[1] = -1;
		else if (flag == 1 && count[1]++ != -1)
			tmp = tmp->next;
	}
	if (count[0] != -1)
		count[1] = stack_size(stack) - count[0];
}