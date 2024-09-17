/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_action.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasano <shunkotkg0141@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:24:32 by sasano            #+#    #+#             */
/*   Updated: 2024/09/18 00:14:13 by sasano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a, int flag)
{
	t_node *new_top;
	t_node *new_next;
	t_node *new_prev;
	t_node *new_next_next;

	if (!a || !a->top || !a->top->next)
		return ;
	new_next  = a->top;
	new_top = a->top->next;
	new_prev = a->top->prev;
	new_next_next = a->top->next->next;

	new_top->next = new_next;
	new_top->prev = new_prev;
	new_next->prev = new_top;
	new_next->next = new_next_next;
	new_prev->next = new_top;
	new_next_next->prev = new_next;
	a->top = new_top;
	if (flag)
		ft_putstr_fd("sa\n", 1);
}

void	ss(t_stack *a, t_stack *b, int flag)
{
	sa(a, 0);
	sb(b, 0);
	if (flag)
		ft_putstr_fd("ss\n", 1);
}


void	pa(t_stack *a, t_stack *b)
{
	t_node	*tmp;

	if (!b || !b->top)
		return ;
	tmp = b->top;
	if (stack_size(b) == 1)
		b->top = NULL;
	else 
	{
		b->top = b->top->next;
		b->top->prev = tmp->prev;
		b->top->prev->next = b->top;
	}
	tmp->next = a->top;
	tmp->prev = a->top->prev;
	a->top->prev->next = tmp;
	a->top->prev = tmp;
	a->top = tmp;
	ft_putstr_fd("pa\n", 1);
}

void pb(t_stack *a, t_stack *b)
{
    t_node *tmp;
	
    if (a && a->top)
    {
        tmp = a->top;
        a->top = a->top->next;
        a->top->prev = tmp->prev;
        a->top->prev->next = a->top;
        if (!b->top)
        {
            b->top = tmp;
            tmp->next = tmp;
            tmp->prev = tmp;
        }
        else
        {
            tmp->next = b->top;
            tmp->prev = b->top->prev;
            b->top->prev->next = tmp;
            b->top->prev = tmp;
            b->top = tmp;
        }
    }
    ft_putstr_fd("pb\n", 1);
}

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