/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasano <shunkotkg0141@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:48:41 by sasano            #+#    #+#             */
/*   Updated: 2024/11/17 02:13:19 by sasano           ###   ########.fr       */
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
			break;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	int		*coords;
	t_stack	*a;
	t_stack	*b;

	//入力チェック
	check_input(&argc, &argv);
	//座標圧縮
	coords = coordinateCompression(argc, argv);
	// 重複がないかチェック
	check_duplicate(argc - 1, coords);
	//スタック作成
	a = create_stack(argc, coords);
	b = (t_stack *)malloc(sizeof(t_stack) * 1);
	if (!b)
		exit(1);
	b->top = NULL;
	free(coords);
	// 要素が２つか３つならソート & ソート済みかチェック
	if (sort_two_element(a) || sort_three_element(a) || check_sorted_stack(a, b))
		return (0);
	// ２つをスタックBに移動
	move_two_node_to_b(a,b);
	// スタックAの残りが３つになるまでソート
	// スタックAの中で、最も少ない手順でスタックBにソートして移動させる数値を探索し、その手順通りに移動させる
	while(stack_size(a) > 3)
		move_stack(a, b, search_insert_min_node(a, b));
	// 要素が３つになったスタックAをソート
	sort_three_element(a);
	// スタックBからスタックAにソートしながら戻す
	return_stack_to_a_from_b(a, b);
	rotate_sort_a(a);
	// print_stack(a, b);
	return (0);
}

// void			end(void) __attribute__((destructor));
// void	end(void)
// {
// 	system("sudo leaks push_swap");
// }