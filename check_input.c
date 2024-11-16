/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasano <shunkotkg0141@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:01:32 by sasano            #+#    #+#             */
/*   Updated: 2024/11/17 02:57:03 by sasano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 2次元配列を連結し、新しい2次元配列を生成する
char    **ft_array_concat(char **array1, char **array2)
{
    char **new_array;
    int i;
    int j;

    // 配列の長さを取得
    i = -1;
    while (array1 && array1[++i])
        ;
    j = -1;
    while (array2[++j])
        ;
    // 新しい配列を生成
    new_array = (char **)malloc(sizeof(char *) * (i + j + 1));
    if (!new_array)
        exit(1);

    // 配列を連結
    i = -1;
    while (array1 && array1[++i])
        new_array[i] = array1[i];
    j = -1;
    while (array2[++j])
        new_array[i + j] = array2[j];
    new_array[i + j] = NULL;
    
    return (new_array);
}

int format_split(char ***formated_input, char *str)
{
    char **split;
    int count;
    int i;
    int j;

    count = 0;
    // 空白で分割
    split = ft_split(str, ' ');
    // split = ft_split(str, '-');
    i = -1;
    while (split[++i])
    {
        j = -1;
        while (split[i][++j])
        {
            // 整数以外が入力された場合の処理
            if (!ft_isdigit(split[i][j]) && split[i][j] != '-')
            {
                ft_putstr_fd("Error\n", 2);
                exit(0);
            }
        }
        count++;
    }
    // 連結
    *formated_input = ft_array_concat(*formated_input, split);
    return (count);
}

int  format_input(int *argc, char **argv[])
{
    char **formated_input;
    int i;
    int count;

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

int	is_outside_int_range(const char *str)
{
	int		sign;
	int		digit;
	long	value;

    while (isspace((unsigned char)*str))
        str++;
    sign = 1;
    if (*str == '-')
    {
        sign = -1;
        str++;
    } 
    else if (*str == '+')
        str++;
    if (!isdigit((unsigned char)*str))
        return (1);
    value = 0;
    while (*str)
	{
        digit = *str - '0';
        if (sign == 1 && (value > (INT_MAX - digit) / 10))
            return (1);
        else if (value > (-(long)INT_MIN - digit) / 10)
            return (1);
        value = value * 10 + digit;
        str++;
    }
    return (0);
}


int check_duplicate(int array_size, int *array)
{
    int i;
    int j;

    i = -1;
    while (++i < array_size - 1)
    {
        j = i;
        while (++j < array_size)
        {
            if (array[i] == array[j])
            {
                ft_putstr_fd("Error\n", 2);
                exit(0);
            }
        }
    }
    return (0);
}

void check_input(int *argc, char **argv[])
{
    int i;
	// 引数がない場合
	if (*argc < 2)
		exit(0);
    // フォーマットを整える
    format_input(argc, argv);
    // 重複がないかチェック
    // check_duplicate(*argc, *argv);
    // ""や" "が入力された場合の処理
    if (*argc < 2)
    {
        ft_putstr_fd("Error\n", 2);
        exit(0);
    }
    // 範囲を超えていないかチェック
    i = *argc;
    while (--i)
    {
        if (is_outside_int_range((*argv)[i]))
        {
            ft_putstr_fd("Error\n", 2);
            exit(0);
        }
    }
    return ;
}
