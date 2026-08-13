/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustde-s <gustde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 18:50:21 by mamatos-          #+#    #+#             */
/*   Updated: 2026/08/13 17:36:37 by gustde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	ft_sqrt(int number)
{
	int	i;

	i = 0;
	while (i * i < number)
	{
		if (i * i == number)
			return (i);
		i++;
	}
	return (i - 1);
}

static int	chunks_b(t_list **stack_a, t_list **stack_b, int size)
{
	int		chunk_size;
	int		pushed_b;
	t_count	op;
	int		i;

	chunk_size = ft_sqrt(size) * 1.5;
	pushed_b = 0;
	i = 0;
	while (*stack_a)
	{
		if ((*stack_a)->index <= i++)
		{
			push_b(stack_b, stack_a, &op);
			rotate_b(stack_b, &op);
			pushed_b++;
		}
		else if((*stack_a)->index <= i + chunk_size)
		{
			push_b(stack_b, stack_a, &op);
			pushed_b++;
		}
		else
			rotate_a(stack_a, &op);
		if (pushed_b >= i + chunk_size)
            i += chunk_size;
	}
	return (pushed_b);
}

static void bring_max_to_top(t_list **stack_b, int max_pos, int b_size, t_count *op)
{
    if (max_pos <= b_size / 2)
    {
        while (max_pos > 0)
        {
            rotate_b(stack_b, op); 
            max_pos--;
        }
    }
    else
    {
        while (max_pos < b_size)
        {
            reverse_rotate_b(stack_b, op);
            max_pos++;
        }
    }
}

static void	push_back_to_a(t_list **stack_a, t_list **stack_b, t_count *op)
{
    int max_pos;
    int b_size;

    while (*stack_b)
    {
        b_size = lst_size(*stack_b);
        max_pos = get_max_index_pos(stack_b);     
        bring_max_to_top(stack_b, max_pos, b_size, op);
        push_a(stack_a, stack_b, op);
    }
}
void sort_medium(t_list **stack_a, t_list **stack_b, t_count *op)
{
    int size;

    size = lst_size(*stack_a);
    if (size <= 1)
        return ;
    chunks_b(stack_a, stack_b, size);
    push_back_to_a(stack_a, stack_b, op);
}
