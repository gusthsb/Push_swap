/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustde-s <gustde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 17:23:39 by gustde-s          #+#    #+#             */
/*   Updated: 2026/08/18 19:14:00 by gustde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	print_disorder(double disorder)
{
	put_str_fd("[bench] disorder:  ");
	print_double_2dec(disorder * 100.0);
	put_str_fd("%\n");
}

void	print_strategy(t_config *config)
{
	double	disorder;

	put_str_fd("[bench] strategy:  ");
	put_str_fd(config->strategy);
	put_str_fd(" / ");
	disorder = config->initial_disorder;
	if (disorder < 0.2 && ft_strcmp(config->strategy, "adaptive") == 0)
		put_str_fd("O(n^2)\n");
	else if (disorder < 0.5 && ft_strcmp(config->strategy, "adaptive") == 0)
		put_str_fd("O(n√n)\n");
	else if (disorder >= 0.5 && ft_strcmp(config->strategy, "adaptive") == 0)
		put_str_fd("O(n log n)\n");
	if (ft_strcmp(config->strategy, "simple") == 0)
		put_str_fd("O(n^2)\n");
	else if (ft_strcmp(config->strategy, "medium") == 0)
		put_str_fd("O(n√n)\n");
	else if (ft_strcmp(config->strategy, "complex") == 0)
		put_str_fd("O(n log n)\n");
}

void	print_total_r_ops(t_count	*op)
{
	put_str_fd("[bench] ra: ");
	put_nbr_fd(op->ra);
	put_str_fd("  rb: ");
	put_nbr_fd(op->rb);
	put_str_fd("  rr: ");
	put_nbr_fd(op->rr);
	put_str_fd("  rra: ");
	put_nbr_fd(op->rra);
	put_str_fd("  rrb: ");
	put_nbr_fd(op->rrb);
	put_str_fd("  rrr: ");
	put_nbr_fd(op->rrr);
	put_str_fd("\n");
}

void	print_total_ops(t_count *op)
{
	put_str_fd("[bench] total_ops: ");
	put_nbr_fd(op->count);
	put_str_fd("\n");
	put_str_fd("[bench] sa: ");
	put_nbr_fd(op->sa);
	put_str_fd("  sb: ");
	put_nbr_fd(op->sb);
	put_str_fd("  ss: ");
	put_nbr_fd(op->ss);
	put_str_fd("  pa: ");
	put_nbr_fd(op->pa);
	put_str_fd("  pb: ");
	put_nbr_fd(op->pb);
	put_str_fd("\n");
	print_total_r_ops(op);
}

void	print_bench(t_list *a, t_config *config, t_count *op)
{
	print_disorder(main_disorder(a));
	print_strategy(config);
	print_total_ops(op);
}
