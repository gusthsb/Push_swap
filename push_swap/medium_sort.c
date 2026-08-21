/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustde-s <gustde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 18:50:21 by mamatos-          #+#    #+#             */
/*   Updated: 2026/08/20 23:29:29 by gustde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	push_back_to_a(t_list **a, t_list **b, t_count *op)
{
	int	max_pos;
	int	b_size;

	while (*b)
	{
		b_size = lst_size(*b);
		max_pos = get_max_index_pos(b);
		bring_max_to_top(b, max_pos, b_size, op);
		push_a(a, b, op);
	}
}

void	sort_medium(t_list **a, t_list **b, t_count *op)
{
	int	size;

	size = lst_size(*a);
	if (size <= 5)
	{
		sort_simple(a, b, op);
		return ;
	}
	if (size <= 1)
		return ;
	chunks_b(a, b, size, op);
	push_back_to_a(a, b, op);
}
