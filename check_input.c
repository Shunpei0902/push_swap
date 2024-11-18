/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasano <shunkotkg0141@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:01:32 by sasano            #+#    #+#             */
/*   Updated: 2024/11/17 05:25:45 by sasano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_array_concat(char **array1, char **array2)
{
	char	**new_array;
	int		i;
	int		j;

	i = -1;
	while (array1 && array1[++i])
		;
	j = -1;
	while (array2[++j])
		;
	new_array = (char **)malloc(sizeof(char *) * (i + j + 1));
	if (!new_array)
		exit(1);
	i = -1;
	while (array1 && array1[++i])
		new_array[i] = array1[i];
	j = -1;
	while (array2[++j])
		new_array[i + j] = array2[j];
	new_array[i + j] = NULL;
	return (new_array);
}

int	format_split(char ***formated_input, char *str)
{
	char	**split;
	int		count;
	int		i;
	int		j;

	count = 0;
	split = ft_split(str, ' ');
	i = -1;
	while (split[++i])
	{
		j = -1;
		while (split[i][++j])
		{
			if (!ft_isdigit(split[i][j]) && split[i][j] != '-')
				error();
		}
		count++;
	}
	*formated_input = ft_array_concat(*formated_input, split);
	return (count);
}

int	format_input(int *argc, char **argv[])
{
	char	**formated_input;
	int		i;
	int		count;

	formated_input = (char **)ft_calloc(2, sizeof(char *));
	if (!formated_input)
		exit(1);
	formated_input[0] = ft_strdup((*argv)[0]);
	i = 0;
	count = 1;
	while (i++ < *argc - 1)
		count += format_split(&formated_input, (*argv)[i]);
	*argv = formated_input;
	*argc = count;
	return (0);
}

void	check_input(int *argc, char **argv[])
{
	int	i;

	if (*argc < 2)
		exit(0);
	format_input(argc, argv);
	if (*argc < 2)
		error();
	i = *argc;
	while (--i)
		is_outside_int_range((*argv)[i]);
	return ;
}
