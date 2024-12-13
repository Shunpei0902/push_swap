/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasano <shunkotkg0141@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 00:44:10 by sasano            #+#    #+#             */
/*   Updated: 2024/11/18 14:27:24 by sasano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_node	*node;
	t_node	*tmp;

	if (!stack || !stack->top)
	{
		free(stack);
		return ;
	}
	node = stack->top;
	while (1)
	{
		tmp = node->next;
		free(node);
		if (tmp == stack->top)
			break ;
		node = tmp;
	}
	free(stack);
}

void	free_search_result(t_search_result *result)
{
	if (!result)
		return ;
	free(result->a_head_count);
	free(result->b_head_count);
	free(result);
}

void	free_str_array(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void print_str_array(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_printf("str[%d]: %s : %p\n", i, str[i], &(str[i]));
		i++;
	}
	ft_printf("str[%d]: %s : %p\n", i, str[i], &(str[i]));
	ft_printf("str: %p\n", &str);
}
