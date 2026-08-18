/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustde-s <gustde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 17:04:14 by gustde-s          #+#    #+#             */
/*   Updated: 2026/08/13 17:22:48 by gustde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	sort_complex(t_list **stack_a, t_list **stack_b, t_count *op)
{
	int	bit;
	int	i;
	int	bit_size;
	int	size;

	fprintf(stderr, "CAIU NO COMPLEX\n");
	i = 0;
	size = lst_size(*stack_a);
	while (((size - 1) >> i) != 0)
		i++;
	bit_size = i;
	bit = 0;
	while (bit < bit_size)
	{
		i = 0;
		while (i < size)
		{
			if ((((*stack_a)->index >> bit)& 1) == 0)
				push_b(stack_b, stack_a, op);
			else
				rotate_a(stack_a, op);
			i++;
		}
		while (*stack_b)
			push_a(stack_a, stack_b, op);
		bit++;
	}
}
