/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate_compression.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasano <shunkotkg0141@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:54:42 by sasano            #+#    #+#             */
/*   Updated: 2024/11/17 04:47:22 by sasano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_qsort(int *sorted_coords, int length)
{
	int	i;
	int	j;
	int	pivot;
	int	tmp;

	if (length < 2)
		return ;
	pivot = sorted_coords[length / 2];
	i = -1;
	j = length;
	while (1)
	{
		while (sorted_coords[++i] < pivot)
			;
		while (sorted_coords[--j] > pivot)
			;
		if (i >= j)
			break ;
		tmp = sorted_coords[i];
		sorted_coords[i] = sorted_coords[j];
		sorted_coords[j] = tmp;
	}
	ft_qsort(sorted_coords, i);
	ft_qsort(sorted_coords + i, length - i);
}

static int	*ft_bsearch(int num, int *base, int length)
{
	int	low;
	int	high;
	int	mid;

	low = 0;
	high = length - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (num == base[mid])
			return (&base[mid]);
		else if (num < base[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}
	return (NULL);
}

static void	error_coords(int *coords, int *sorted_coords,
		int *compressed_coords)
{
	if (coords)
		free(coords);
	if (sorted_coords)
		free(sorted_coords);
	if (compressed_coords)
		free(compressed_coords);
	error();
}

int	*coordinate_compression(int argc, char *argv[])
{
	int	i;
	int	*coords;
	int	*sorted_coords;
	int	*compressed_coords;

	coords = (int *)malloc(sizeof(int) * (argc - 1));
	sorted_coords = (int *)malloc(sizeof(int) * (argc - 1));
	compressed_coords = (int *)malloc(sizeof(int) * (argc - 1));
	if (!coords || !sorted_coords || !compressed_coords)
		error_coords(coords, sorted_coords, compressed_coords);
	i = -1;
	while (++i < argc - 1)
	{
		coords[i] = ft_atoi(argv[i + 1]);
		sorted_coords[i] = coords[i];
	}
	ft_qsort(sorted_coords, argc - 1);
	i = -1;
	while (++i < argc - 1)
		compressed_coords[i] = (int *)ft_bsearch(coords[i], sorted_coords, argc
				- 1) - sorted_coords;
	free(coords);
	free(sorted_coords);
	return (compressed_coords);
}
