/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_action_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasano <shunkotkg0141@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:41:07 by sasano            #+#    #+#             */
/*   Updated: 2024/11/18 14:34:17 by sasano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a, int flag)
{
	if (!a || !a->top)
		return ;
	a->top = a->top->next;
	if (flag)
		ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack *b, int flag)
{
	if (!b || !b->top)
		return ;
	b->top = b->top->next;
	if (flag)
		ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack *a, t_stack *b, int flag)
{
	ra(a, 0);
	rb(b, 0);
	if (flag)
		ft_putstr_fd("rr\n", 1);
}

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
