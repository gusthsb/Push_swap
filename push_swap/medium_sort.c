/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustde-s <gustde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 18:50:21 by mamatos-          #+#    #+#             */
/*   Updated: 2026/08/13 16:38:42 by gustde-s         ###   ########.fr       */
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

	chunk_size = ft_sqrt(size) * 1.5;
	pushed_b = 0;
	while (*stack_a)
	{
		if ((*stack_a)->index <= pushed_b)
		{
			push_b(stack_b, stack_a, &op);
			pushed_b++;
		}
		else if((*stack_a)->index <= pushed_b + chunk_size)
		{
			push_b(stack_b, stack_a, &op);
			pushed_b++;
			rotate_b(stack_b, &op);
		}
		else
			rotate_a(stack_a, &op);
	}
}

static void	push_back(t_list **stack_a, t_list **stack_b)
{
	t_count	op;
	int		max_index;
	int		b_size;

	while (*stack_b)
	{
		b_size = lst_size(*stack_b);
		max_index = get_max_index_pos(*stack_b);
		if (max_index <= b_size / 2)
		{
			while (max_index > 0)
			{
				
			}
		}
	}
}