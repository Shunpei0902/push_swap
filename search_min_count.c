/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_min_count.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasano <shunkotkg0141@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 05:01:14 by sasano            #+#    #+#             */
/*   Updated: 2024/11/17 05:01:44 by sasano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	handle_case_a0_b0(int *count_array, t_search_result *result,
		t_search_result *min_result)
{
	if (result->a_head_count[0] != -1 && result->b_head_count[0] != -1)
	{
		if (result->a_head_count[0] >= result->b_head_count[0] && (!min_result
				|| min_result->min_count > result->a_head_count[0]))
			count_array[0] = result->a_head_count[0] + 1;
		else if (result->a_head_count[0] < result->b_head_count[0]
			&& (!min_result || min_result->min_count > result->b_head_count[0]))
			count_array[0] = result->b_head_count[0] + 1;
	}
	return (0);
}

static int	handle_case_a0_b1(int *count_array, t_search_result *result,
		t_search_result *min_result)
{
	if (result->a_head_count[0] != -1 && result->b_head_count[1] != -1
		&& (!min_result || min_result->min_count > result->a_head_count[0]
			+ result->b_head_count[1]))
		count_array[1] = result->a_head_count[0] + result->b_head_count[1] + 1;
	return (0);
}

static int	handle_case_a1_b0(int *count_array, t_search_result *result,
		t_search_result *min_result)
{
	if (result->a_head_count[1] != -1 && result->b_head_count[0] != -1
		&& (!min_result || min_result->min_count > result->a_head_count[1]
			+ result->b_head_count[0]))
		count_array[2] = result->a_head_count[1] + result->b_head_count[0] + 1;
	return (0);
}

static int	handle_case_a1_b1(int *count_array, t_search_result *result,
		t_search_result *min_result)
{
	if (result->a_head_count[1] != -1 && result->b_head_count[1] != -1)
	{
		if (result->a_head_count[1] >= result->b_head_count[1] && (!min_result
				|| min_result->min_count > result->a_head_count[1]))
			count_array[3] = result->a_head_count[1] + 1;
		else if (result->a_head_count[1] < result->b_head_count[1]
			&& (!min_result || min_result->min_count > result->b_head_count[1]))
			count_array[3] = result->b_head_count[1] + 1;
	}
	return (0);
}

t_search_result	*search_min_count(int *count_array, t_search_result *result,
		t_search_result *min_result)
{
	handle_case_a0_b0(count_array, result, min_result);
	handle_case_a0_b1(count_array, result, min_result);
	handle_case_a1_b0(count_array, result, min_result);
	handle_case_a1_b1(count_array, result, min_result);
	return (eval_min_count(count_array, result, min_result));
}
