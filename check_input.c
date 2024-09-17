/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasano <shunkotkg0141@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:01:32 by sasano            #+#    #+#             */
/*   Updated: 2024/09/18 00:03:38 by sasano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 2次元配列を連結し、新しい2次元配列を生成する
char **ft_array_concat(char **array1, char **array2)
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
    i = -1;
    while (split[++i])
    {
        j = -1;
        while (split[i][++j])
        {
            // 整数以外が入力された場合の処理
            if (!ft_isdigit(split[i][j]))
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


int check_duplicate(int argc, char *argv[])
{
    int i;
    int j;

    i = 0;
    while (++i < argc)
    {
        j = i;
        while (++j < argc)
        {
            if (ft_strlen(argv[i]) != ft_strlen(argv[j]))
                continue;
            if (!ft_strncmp(argv[i], argv[j], ft_strlen(argv[i])))
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
	// 引数がない場合
	if (*argc < 2)
		exit(0);
    // フォーマットを整える
    format_input(argc, argv);
    // 重複がないかチェック
    check_duplicate(*argc, *argv);
    // ""や" "が入力された場合の処理
    if (*argc < 2)
    {
        ft_putstr_fd("Error\n", 2);
        exit(0);
    }
    // 範囲を超えていないかチェック
    // check_range(*argc, *argv);

    return ;
}
