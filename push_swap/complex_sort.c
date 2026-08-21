/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamatos- <mamatos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 17:04:14 by gustde-s          #+#    #+#             */
/*   Updated: 2026/08/20 23:48:52 by mamatos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	count_bits(int size)
{
	int	i;

	i = 0;
	while (((size - 1) >> i) != 0)
		i++;
	return (i);
}

void	sort_complex(t_list **stack_a, t_list **stack_b, t_count *op)
{
	int	bit;
	int	i;
	int	bit_size;
	int	size;

	size = lst_size(*stack_a);
	if (size <= 5)
		return (sort_simple(stack_a, stack_b, op));
	bit_size = count_bits(size);
	bit = 0;
	while (bit < bit_size)
	{
		i = 0;
		while (i++ < size)
		{
			if ((((*stack_a)->index >> bit) & 1) == 0)
				push_b(stack_b, stack_a, op);
			else
				rotate_a(stack_a, op);
		}
		while (*stack_b)
			push_a(stack_a, stack_b, op);
		bit++;
	}
}
