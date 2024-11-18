/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_insert_min_node.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasano <shunkotkg0141@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:51:31 by sasano            #+#    #+#             */
/*   Updated: 2024/11/18 14:32:30 by sasano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_search_result	*search_insert_min_count(t_stack *a, t_stack *b,
		t_search_result *result, t_search_result *min_result)
{
	int	count;
	int	*count_array;

	if (min_result)
		search_insert_position_count(a, result->target_a_node,
			result->a_head_count, min_result->min_count);
	else
		search_insert_position_count(a, result->target_a_node,
			result->a_head_count, -1);
	result->inserted_b_node = search_on_inserted_b_node(result->target_a_node->value,
			b);
	count = check_rest_count(result, min_result);
	if (count)
		search_insert_position_count(b, result->inserted_b_node,
			result->b_head_count, count);
	count_array = (int *)ft_calloc(4, sizeof(int));
	if (!count_array)
		exit(1);
	return (search_min_count(count_array, result, min_result));
}

t_search_result	*create_t_search_result(t_node *node)
{
	t_search_result	*result;

	result = (t_search_result *)malloc(sizeof(t_search_result) * 1);
	if (!result)
		exit(1);
	result->a_head_count = (int *)ft_calloc(2, sizeof(int));
	if (!result->a_head_count)
		exit(1);
	result->b_head_count = (int *)ft_calloc(2, sizeof(int));
	if (!result->b_head_count)
		exit(1);
	result->min_count = 0;
	result->target_a_node = node;
	result->inserted_b_node = NULL;
	return (result);
}

static t_search_result	*search_from_below(t_stack *a, t_stack *b, t_node *node,
		t_search_result *min_result)
{
	t_search_result	*result;
	int				count;

	count = 0;
	while (count++)
	{
		result = create_t_search_result(node);
		min_result = search_insert_min_count(a, b, result, min_result);
		node = node->prev;
		if (node == a->top->prev || count >= min_result->min_count)
			break ;
	}
	return (min_result);
}

static t_search_result	*search_from_above(t_stack *a, t_stack *b, t_node *node,
		t_search_result *min_result)
{
	t_search_result	*result;
	int				count;

	count = 0;
	while (++count)
	{
		result = create_t_search_result(node);
		min_result = search_insert_min_count(a, b, result, min_result);
		node = node->next;
		if (node == a->top || count >= min_result->min_count)
			break ;
	}
	return (min_result);
}

t_search_result	*search_insert_min_node(t_stack *a, t_stack *b)
{
	t_search_result	*min_result;
	t_node			*node;

	min_result = NULL;
	node = a->top;
	min_result = search_from_above(a, b, node, min_result);
	node = a->top->prev;
	min_result = search_from_below(a, b, node, min_result);
	return (min_result);
}
