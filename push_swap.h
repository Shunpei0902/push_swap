/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasano <shunkotkg0141@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 00:14:36 by sasano            #+#    #+#             */
/*   Updated: 2024/09/18 00:15:52 by sasano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// # define MAX 100
# define sb sa

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct s_node
{
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
}					t_stack;

typedef struct s_search_result
{
	int 			min_count;
	int 			*a_head_count;
	int 			*b_head_count;
	t_node			*inserted_b_node;
	t_node			*target_a_node;
}					t_search_result;

void				sa(t_stack *stack_a, int flag);
void				ss(t_stack *a, t_stack *b, int flag);
void				pa(t_stack *a, t_stack *b);
void				pb(t_stack *a, t_stack *b);
void				ra(t_stack *a, int flag);
void				rb(t_stack *b, int flag);
void				rr(t_stack *a, t_stack *b, int flag);
void				rra(t_stack *a, int flag);
void				rrb(t_stack *b, int flag);
void				rrr(t_stack *a, t_stack *b, int flag);
void 				check_input(int *argc, char **argv[]);
int					*coordinateCompression(int argc, char *argv[]);
size_t				stack_size(t_stack *stack);
int 				sort_two_element(t_stack *a);
int 				sort_three_element(t_stack *a);
void				move_two_node_to_b(t_stack *a, t_stack *b);
t_search_result		*search_insert_min_node(t_stack *a, t_stack *b);
void				move_stack(t_stack *a, t_stack *b, t_search_result *result);
void 				return_stack_to_a_from_b(t_stack *a, t_stack *b);
void 				rotate_sort_a(t_stack *a);
void				free_stack(t_stack *stack);
void				free_search_result(t_search_result *result);
void				print_stack(t_stack *a, t_stack *b);
void 				print_argv(int i, char **str);

#endif
