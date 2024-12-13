/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasano <shunkotkg0141@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 00:14:36 by sasano            #+#    #+#             */
/*   Updated: 2024/11/18 14:37:40 by sasano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <ctype.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>

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
	int				min_count;
	int				*a_head_count;
	int				*b_head_count;
	t_node			*inserted_b_node;
	t_node			*target_a_node;
}					t_search_result;

void				sa(t_stack *a, int flag);
void				sb(t_stack *b, int flag);
void				ss(t_stack *a, t_stack *b, int flag);
void				pa(t_stack *a, t_stack *b);
void				pb(t_stack *a, t_stack *b);
void				ra(t_stack *a, int flag);
void				rb(t_stack *b, int flag);
void				rr(t_stack *a, t_stack *b, int flag);
void				rra(t_stack *a, int flag);
void				rrb(t_stack *b, int flag);
void				rrr(t_stack *a, t_stack *b, int flag);
void				check_input(int *argc, char **argv[]);
int					*coordinate_compression(int argc, char *argv[]);
int					check_duplicate(int array_size, int *array);
int					is_outside_int_range(const char *str);
size_t				stack_size(t_stack *stack);
int					sort_two_element(t_stack *a);
int					sort_three_element(t_stack *a);
void				move_two_node_to_b(t_stack *a, t_stack *b);
t_search_result		*search_insert_min_node(t_stack *a, t_stack *b);
t_search_result		*search_min_count(int *count_array, t_search_result *result,
						t_search_result *min_result);
void				search_insert_position_count(t_stack *stack, t_node *target,
						int *count, int min_count);
int					search_on_inserted_a_count(int value, t_stack *a);
t_node				*search_on_inserted_b_node(int value, t_stack *b);
t_search_result		*eval_min_count(int *count_array, t_search_result *result,
						t_search_result *min_result);
int					check_rest_count(t_search_result *result,
						t_search_result *min_result);
int					com_count(int *count_array);
void				fill_minus(t_search_result *result, int index);
void				move_stack(t_stack *a, t_stack *b, t_search_result *result);
void				return_stack_to_a_from_b(t_stack *a, t_stack *b);
void				rotate_sort_a(t_stack *a);
void				free_stack(t_stack *stack);
void				free_search_result(t_search_result *result);
// void				free_str_array(int len, char **str);
void				free_str_array(char **str);
void				error(void);
void print_str_array(char **str);

#endif
