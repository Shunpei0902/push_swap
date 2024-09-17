/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_action_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasano <shunkotkg0141@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:41:07 by sasano            #+#    #+#             */
/*   Updated: 2024/09/16 13:01:50 by sasano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *a, int flag)
{
	if (!a || !a->top)
		return ;
	a->top = a->top->prev;
	if (flag)
		ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack *b, int flag)
{
	if (!b || !b->top)
		return ;
	b->top = b->top->prev;
	if (flag)
		ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack *a, t_stack *b, int flag)
{
	rra(a, 0);
	rrb(b, 0);
	if (flag)
		ft_putstr_fd("rrr\n", 1);
}
