/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasano <shunkotkg0141@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 22:54:23 by sasano            #+#    #+#             */
/*   Updated: 2024/09/17 15:50:31 by sasano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	stack_size(t_stack *stack)
{
	size_t size;
	t_node *node;

	if (!stack || !stack->top)
		return (0);

	size = 0;
	node = stack->top;
	while (1)
	{
		size++;
		node = node->next;
		if (node == stack->top)
			break;
	}
	return (size);
}

void	move_two_node_to_b(t_stack *a, t_stack *b)
{
	pb(a, b);
	pb(a, b);
}


void move_stack(t_stack *a, t_stack *b, t_search_result *result)
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
}

int sort_three_element(t_stack *a)
{
	if (stack_size(a) != 3)
		return (0);
	// 1 2 3
	if (a->top->value < a->top->next->value && a->top->next->value < a->top->prev->value)
		return (1);
	// 2 1 3
	else if (a->top->value > a->top->next->value && a->top->value < a->top->prev->value)
		sa(a, 1);
	// 2 3 1
	else if (a->top->value < a->top->next->value && a->top->value > a->top->prev->value)
		rra(a, 1);
	// 3 2 1
	else if (a->top->value > a->top->next->value && a->top->next->value > a->top->prev->value)
	{
		sa(a, 1);
		rra(a, 1);
	}
	// 3 1 2
	else if (a->top->value > a->top->next->value && a->top->next->value < a->top->prev->value)
		ra(a, 1);
	// 1 3 2
	else if (a->top->value < a->top->next->value && a->top->next->value > a->top->prev->value)
	{
		sa(a, 1);
		ra(a, 1);
	}
	return (1);
}

int sort_two_element(t_stack *a)
{
	if (stack_size(a) != 2)
		return (0);
	if (a->top->value > a->top->next->value)
		sa(a, 1);
	return (1);
}

int search_on_inserted_a_count(int value, t_stack *a)
{
	int count;
    t_node *node;

	count = 0;
    node = a->top;
    while (1) {
        // valueが一番大きいとき, valueが一番小さいとき, それ以外
        if (((node->value > value || node->prev->value < value) && node->prev->value > node->value) || (node->value > value && node->prev->value < value))
            return (count);
        node = node->next;
        if (node == a->top)
            break;
		count++;
    }
    return (count);
}


void return_stack_to_a_from_b(t_stack *a, t_stack *b)
{
	int count;
	int size;

	while (b->top)
	{
		if ((a->top->value > b->top->value && a->top->prev->value < b->top->value) || ((a->top->prev->value < b->top->value || a->top->value > b->top->value) && a->top->value < a->top->prev->value))
			pa(a, b);
		else
		{
			size = stack_size(a);
			count = search_on_inserted_a_count(b->top->value, a);
			if (count <= size/ 2)
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
	}
}

void rotate_sort_a(t_stack *a)
{
	t_node *node;
	int size;
	int count;
	

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

