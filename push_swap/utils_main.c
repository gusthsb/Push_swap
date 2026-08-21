/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustde-s <gustde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 22:41:18 by gustde-s          #+#    #+#             */
/*   Updated: 2026/08/20 22:41:32 by gustde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	handle_output(t_config *config, t_count *op)
{
	if (config->bench_mode)
	{
		print_disorder(config->initial_disorder);
		print_strategy(config);
		print_total_ops(op);
	}
}

int	should_sort(t_list *stack_a)
{
	return (stack_a && lst_size(stack_a) > 1 && !is_sorted(stack_a));
}

void	cleanup(t_list **stack_a, t_list **stack_b)
{
	ft_lstclear(stack_a);
	ft_lstclear(stack_b);
}
