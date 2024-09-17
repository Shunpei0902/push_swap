/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_insert_min_node.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasano <shunkotkg0141@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:51:31 by sasano            #+#    #+#             */
/*   Updated: 2024/09/17 15:39:26 by sasano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 必要のない値に-1を代入
void fill_minus(t_search_result *result, int index)
{
    if (index == 0)
    {
        result->a_head_count[1] = -1;
        result->b_head_count[1] = -1;
    }
    else if (index == 1)
    {
        result->a_head_count[1] = -1;
        result->b_head_count[0] = -1;
    }
    else if (index == 2)
    {
        result->a_head_count[0] = -1;
        result->b_head_count[1] = -1;
    }
    else if (index == 3)
    {
        result->a_head_count[0] = -1;
        result->b_head_count[0] = -1;
    }
}

// 手順を比較
int com_count(int *count_array)
{
    int i;
    int value;
    int index;

    i = 0;
    value = 0;
    index = 0;
    while (i < 4)
    {
        if (value == 0 || (count_array[i] != 0 && value > count_array[i]))
        {
            value = count_array[i];
            index = i;
        }
        i++;
    }
    return (index);
}

// 最短手数を比較
t_search_result *eval_min_count(int *count_array, t_search_result *result, t_search_result *min_result)
{
    int min_count_index;

    min_count_index = com_count(count_array);
    fill_minus(result, min_count_index);
    result->min_count = count_array[min_count_index];
    if (!min_result || (min_result->min_count > result->min_count && result->min_count != 0))
    {
        if (min_result)
            free_search_result(min_result);
        min_result = result;
    }
    else
        free_search_result(result);
    return (min_result);
}

// 最短手数を計算
t_search_result *search_min_count(int *count_array, t_search_result *result, t_search_result *min_result)
{
    if (result->a_head_count[0] != -1 && result->b_head_count[0] != -1)
    {
        if (result->a_head_count[0] >= result->b_head_count[0] && (!min_result || min_result->min_count > result->a_head_count[0]))
            count_array[0] = result->a_head_count[0] + 1;
        else if (result->a_head_count[0] < result->b_head_count[0] && (!min_result || min_result->min_count > result->b_head_count[0]))
            count_array[0] = result->b_head_count[0] + 1;
    }
    if (result->a_head_count[0] != -1 && result->b_head_count[1] != -1 && (!min_result || min_result->min_count > result->a_head_count[0] + result->b_head_count[1]))
        count_array[1] = result->a_head_count[0] + result->b_head_count[1] + 1;
    if (result->a_head_count[1] != -1 && result->b_head_count[0] != -1 && (!min_result || min_result->min_count > result->a_head_count[1] + result->b_head_count[0]))
        count_array[2] = result->a_head_count[1] + result->b_head_count[0] + 1;
    if (result->a_head_count[1] != -1 && result->b_head_count[1] != -1)
    {
        if (result->a_head_count[1] >= result->b_head_count[1] && (!min_result || min_result->min_count > result->a_head_count[1]))
            count_array[3] = result->a_head_count[1] + 1;
        else if (result->a_head_count[1] < result->b_head_count[1] && (!min_result || min_result->min_count > result->b_head_count[1]))
            count_array[3] = result->b_head_count[1] + 1;
    }
    return (eval_min_count(count_array, result, min_result));
}

int check_rest_count(t_search_result *result, t_search_result *min_result)
{
    int count;

    if (!min_result)
        return (-1);
    count = min_result->min_count;
    if (result->a_head_count[0] != -1 && result->a_head_count[1] != -1)
    {
        if (result->a_head_count[0] < result->a_head_count[1])
            count -= result->a_head_count[0];
        else
            count -= result->a_head_count[1];
    }
    else if (result->a_head_count[0] != -1)
        count -= result->a_head_count[0];
    else if (result->a_head_count[1] != -1)
        count -= result->a_head_count[1];
    return (count);
}

t_node *search_on_inserted_b_node(int value, t_stack *b)
{
    t_node *node;

    node = b->top;
    while (1) {
        // valueが一番大きいとき, valueが一番小さいとき, それ以外
        if (((node->value < value || node->prev->value > value) && node->prev->value < node->value ) || (node->value < value && node->prev->value > value))
            return (node);
        node = node->next;
        if (node == b->top)
            break;
    }
    return (node);
}

// スタックの対象のノードを先頭に持ってくるのにかかる手数
// min_countより大きい場合はcount=-1にして探索を打ち切る
void search_insert_position_count(t_stack *stack, t_node *target, int *count, int min_count)
{
    int flag;
    t_node *tmp;

    flag = 0;
    tmp = target;
    while(count[0] != -1 || count[1] != -1)
    {
        if ( tmp == stack->top)
            break;
        if (min_count != -1 && min_count <= count[0] && flag == 0)
        {
            count[0] = -1;
            tmp = target;
            flag = 1;
        }
        else if (flag == 0 && count[0]++ != -1)
            tmp = tmp->prev;
        if (min_count != -1 && min_count <= count[1] && flag == 1)
            count[1] = -1;
        else if (flag == 1 && count[1]++ != -1)
            tmp = tmp->next;
    }
    if (count[0] != -1)
        count[1] = stack_size(stack) - count[0];
}

t_search_result *search_insert_min_count(t_stack *a, t_stack *b, t_search_result *result, t_search_result *min_result) 
{
    int count;
    int *count_array;

    //　スタックAの対象ノードを先頭に持ってくるのにかかる手数
    if (min_result)
        search_insert_position_count(a, result->target_a_node, result->a_head_count, min_result->min_count);
    else 
        search_insert_position_count(a, result->target_a_node, result->a_head_count, -1);
    // スタックBの移動先を特定
    result->inserted_b_node = search_on_inserted_b_node(result->target_a_node->value, b);
    // 残りの手順数を計算
    count = check_rest_count(result, min_result);
    // スタックBの対象ノードを先頭に持ってくるのにかかる手数
    if (count)
        search_insert_position_count(b, result->inserted_b_node, result->b_head_count, count); 
    //　最短手順を計算
    count_array = (int *)ft_calloc(4, sizeof(int));
    if (!count_array)
        exit(1);
    return (search_min_count(count_array, result, min_result));
}

t_search_result *create_t_search_result(t_node *node)
{
    t_search_result *result;

    result = (t_search_result *)malloc(sizeof(t_search_result) * 1);
    if (!result)
        exit(1);
    result->a_head_count = (int *)ft_calloc(2, sizeof(int));
    if (!result->a_head_count)
        exit(1);
    result->b_head_count = (int *)ft_calloc(2, sizeof(int));
    if (!result->b_head_count)
        exit(1);
    result->min_count = 0;
    result->target_a_node = node;
    result->inserted_b_node = NULL;
    return (result);
}

t_search_result *search_from_below(t_stack *a, t_stack *b, t_node *node, t_search_result *min_result)
{
    t_search_result *result;
    int count;

    count = 0;
    while (count++)
    {
        result = create_t_search_result(node);
        min_result = search_insert_min_count(a, b, result, min_result);
        node = node->prev;
        // 1周 or min_countより大きくなったら探索を打ち切る
        if (node == a->top->prev || count >= min_result->min_count)
            break;
    }
    return (min_result);
}

t_search_result *search_from_above(t_stack *a, t_stack *b, t_node *node, t_search_result *min_result)
{
    t_search_result *result;
    int count;

    count = 0;
    while (++count)
    {
        result = create_t_search_result(node);
        min_result = search_insert_min_count(a, b, result, min_result);
        node = node->next;
        // 1周 or min_countより大きくなったら探索を打ち切る
        if (node == a->top || count >= min_result->min_count)
            break;
    }
    return (min_result);
}

//最小手数でスタックbにソートして移動できるノード, その手順を探索する
t_search_result *search_insert_min_node(t_stack *a, t_stack *b)
{
    t_search_result *min_result;
    t_node *node;

    min_result = NULL;
    // スタックAの上から探索
    node = a->top;
    min_result = search_from_above(a, b, node, min_result);
    // スタックAの下から探索
    node = a->top->prev;
    min_result = search_from_below(a, b, node, min_result);
    return (min_result);
}