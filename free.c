/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasano <shunkotkg0141@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 00:44:10 by sasano            #+#    #+#             */
/*   Updated: 2024/09/17 15:51:22 by sasano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_node *node;
	t_node *tmp;
	int size;
	int i;

	if (!stack)
		return ;
	size = stack_size(stack);
	i = 0;
	node = stack->top;
	while (i++ < size)
	{
		if (i < size - 1)
			tmp = node->next;
		free(node);
		if (i < size - 1)
			node = tmp;	
	}
	free(stack);
}

void free_search_result(t_search_result *result)
{
	if (!result)
		return ;
	free(result->a_head_count);
	free(result->b_head_count);
	// free(result->min_count);
	free(result);
}