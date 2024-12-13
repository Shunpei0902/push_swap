/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasano <shunkotkg0141@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:48:41 by sasano            #+#    #+#             */
/*   Updated: 2024/11/18 14:25:50 by sasano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*create_stack(int argc, int *coords)
{
	int		i;
	t_node	*node;
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack) * 1);
	if (!stack)
		exit(1);
	stack->top = NULL;
	i = argc - 1;
	while (--i >= 0)
	{
		node = (t_node *)malloc(sizeof(t_node) * 1);
		if (!node)
			exit(1);
		node->value = coords[i];
		node->next = stack->top;
		if (stack->top)
			stack->top->prev = node;
		stack->top = node;
	}
	while (node->next)
		node = node->next;
	node->next = stack->top;
	stack->top->prev = node;
	return (stack);
}

static int	check_sorted_stack(t_stack *a, t_stack *b)
{
	t_node	*node;
	int		tmp;

	if (b->top)
		return (0);
	tmp = a->top->value;
	node = a->top->next;
	while (node)
	{
		if (tmp > node->value)
			return (0);
		tmp = node->value;
		node = node->next;
		if (node == a->top)
			break ;
	}
	return (1);
}

static void	push_swap(t_stack *a, t_stack *b)
{
	if (sort_two_element(a) || sort_three_element(a) || check_sorted_stack(a,
			b))
		return ;
	move_two_node_to_b(a, b);
	while (stack_size(a) > 3)
		move_stack(a, b, search_insert_min_node(a, b));
	sort_three_element(a);
	return_stack_to_a_from_b(a, b);
	rotate_sort_a(a);
}

int	main(int argc, char *argv[])
{
	int		*coords;
	t_stack	*a;
	t_stack	*b;

	check_input(&argc, &argv);
	coords = coordinate_compression(argc, argv);
	free_str_array(argv);
	if (check_duplicate(argc - 1, coords))
	{
		free(coords);
		error();
	}
	a = create_stack(argc, coords);
	b = (t_stack *)malloc(sizeof(t_stack) * 1);
	if (!b)
		exit(1);
	b->top = NULL;
	free(coords);
	push_swap(a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}

// void			end(void) __attribute__((destructor));
// void	end(void)
// {
// 	system("leaks -q push_swap");
// }
