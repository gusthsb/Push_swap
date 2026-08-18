/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustde-s <gustde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 19:14:17 by gustde-s          #+#    #+#             */
/*   Updated: 2026/08/18 19:14:21 by gustde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	sort_adaptive(t_list **stack_a, t_list **stack_b, t_count *op)
{
	double	disorder;
	int		size;

	size = lst_size(*stack_a);
	disorder = main_disorder(*stack_a);
	if (disorder < 0.2)
		sort_simple(stack_a, stack_b, op);
	else if (disorder < 0.5)
		sort_medium(stack_a, stack_b, op);
	else
		sort_complex(stack_a, stack_b, op);
}
