/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustde-s <gustde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 17:23:39 by gustde-s          #+#    #+#             */
/*   Updated: 2026/08/11 21:05:27 by gustde-s         ###   ########.fr       */
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

void	print_disorder(double disorder)
{
	ft_printf("[bench] disorder: %f", disorder);
}

void	print_bench(t_count *count)
{
	print_total_ops(count);
}
