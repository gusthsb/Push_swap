/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustde-s <gustde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 17:23:39 by gustde-s          #+#    #+#             */
/*   Updated: 2026/08/11 21:28:16 by gustde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	print_total_ops(t_count *op)
{
	ft_printf("[bench] total_ops: %i\n", op->count);
	ft_printf("[bench] sa: %i sb: %i ss: %i pa: %i pb: %i\n", op->sa, op->sb
	, op->ss, op->pa, op->pb);
	ft_printf("[bench] ra: %i rb: %i rr: %i rra: %i rrb: %i rrr: %i\n", op->ra,
	op->rb, op->rr, op->rra, op->rrb, op->rrr);
}

void	print_strategy(t_config *strategy)
{
	if (ft_strcmp(strategy->strategy, "--simple") == 0)
		ft_printf("[bench] strategy: Simple / O(n2)");
	else if (ft_strcmp(strategy->strategy, "--medium") == 0)
		ft_printf("[bench] strategy: Medium / O(n√n)");
	else if (ft_strcmp(strategy->strategy, "--complex") == 0)
		ft_printf("[bench] strategy: Complex O(n log n)");
	else if (ft_strcmp(strategy->strategy, "--adaptive") == 0)
		ft_printf("[bench] strategy: Adaptive");
}

void	print_disorder(double disorder)
{
	ft_printf("[bench] disorder: %f\n", disorder);
}

void	print_bench(t_count *count)
{
	print_total_ops(count);
}
