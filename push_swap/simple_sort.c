/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamatos- <mamatos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 17:46:16 by mamatos-          #+#    #+#             */
/*   Updated: 2026/08/10 17:46:17 by mamatos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	sort_simple(t_list **stack_a, t_list **stack_b, t_count *op)
{
	int	size;

	fprintf(stderr, "CAIU NO SIMPLE\n");
	size = lst_size(*stack_a);
	if (size == 2)
		two_sorted(stack_a, op);
	else if (size == 3)
		three_sorted(stack_a, op);
	else
	{
		while (size > 3)
		{
			min_to_b(stack_a, stack_b, op);
			size--;
		}
		three_sorted(stack_a, op);
		while (*stack_b)
			push_a(stack_a, stack_b, op);
	}
}
