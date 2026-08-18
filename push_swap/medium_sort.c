/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustde-s <gustde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 18:50:21 by mamatos-          #+#    #+#             */
/*   Updated: 2026/08/13 17:47:07 by gustde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

#include "ft_push_swap.h"

static int	ft_sqrt(int number)
{
	int	i;

	i = 0;
	while (i * i < number)
		i++;
	return (i);
}

static void	push_chunk_element(t_list **a, t_list **b, int chunk_end,
	int mid, t_count *op)
{
	if ((*a)->index <= chunk_end)
	{
		push_b(b, a, op);
		if (*b && (*b)->next != *b
			&& (*b)->index < mid)
			rotate_b(b, op);
	}
	else
		rotate_a(a, op);
}

static void	process_chunk(t_list **a, t_list **b, int chunk_end,
	int mid, int size, t_count *op)
{
	int	i;

	i = 0;
	while (i < size && *a)
	{
		push_chunk_element(a, b, chunk_end, mid, op);
		i++;
	}
}

static void	chunks_b(t_list **a, t_list **b, int size, t_count *op)
{
	int	chunk_size;
	int	chunk_end;
	int	mid;

	chunk_size = ft_sqrt(size) + ft_sqrt(size) / 2;
	chunk_end = chunk_size - 1;
	while (*a)
	{
		mid = chunk_end - chunk_size / 2;
		process_chunk(a, b, chunk_end, mid, size, op);
		if (chunk_end < size - 1)
			chunk_end += chunk_size;
		else
			chunk_end = size - 1;
	}
}

static void	bring_max_to_top(t_list **b, int max_pos, int b_size,
	t_count *op)
{
	if (max_pos <= b_size / 2)
	{
		while (max_pos-- > 0)
			rotate_b(b, op);
	}
	else
	{
		while (max_pos++ < b_size)
			reverse_rotate_b(b, op);
	}
}

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
	fprintf(stderr, "CAIU NO MEDIUM\n");

	size = lst_size(*a);
	if (size <= 1)
		return ;
	chunks_b(a, b, size, op);
	push_back_to_a(a, b, op);
}
