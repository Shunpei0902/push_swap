/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasano <shunkotkg0141@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 04:13:09 by sasano            #+#    #+#             */
/*   Updated: 2024/11/17 04:46:13 by sasano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicate(int array_size, int *array)
{
	int	i;
	int	j;

	i = -1;
	while (++i < array_size - 1)
	{
		j = i;
		while (++j < array_size)
		{
			if (array[i] == array[j])
				error();
		}
	}
	return (0);
}

void	is_outside_int_range(const char *str)
{
	char	sign;
	int		digit;
	long	value;

	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	sign = '+';
	if (*str == '-' || *str == '+')
		sign = *str++;
	if (!ft_isdigit(*str))
		error();
	value = 0;
	while (*str)
	{
		digit = *str - '0';
		if ((sign == '+' && (value > (INT_MAX - digit) / 10)) || (sign == '-'
				&& value > (-(long)INT_MIN - digit) / 10))
			error();
		value = value * 10 + digit;
		str++;
	}
}
