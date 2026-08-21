/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustde-s <gustde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 19:35:50 by gustde-s          #+#    #+#             */
/*   Updated: 2026/08/20 23:13:44 by gustde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_sqrt(int number)
{
	int	i;

	i = 0;
	while (i * i < number)
		i++;
	return (i);
}

void	push_chunk_element(t_list **a, t_list **b, t_chunk *chunk,
		t_count *op)
{
	if ((*a)->index <= chunk->chunk_end)
	{
		push_b(b, a, op);
		if (*b && (*b)->next != *b && (*b)->index < chunk->mid)
			rotate_b(b, op);
	}
	else
		rotate_a(a, op);
}

void	process_chunk(t_list **a, t_list **b, t_chunk *chunk,
		t_count *op)
{
	int	i;
	int	current_a_size;

	i = 0;
	current_a_size = lst_size(*a);
	while (i < current_a_size && *a)
	{
		push_chunk_element(a, b, chunk, op);
		i++;
	}
}

void	chunks_b(t_list **a, t_list **b, int size, t_count *op)
{
	t_chunk	chunk;
	int		chunk_size;

	chunk_size = ft_sqrt(size) + ft_sqrt(size) / 2;
	chunk.chunk_end = chunk_size - 1;
	chunk.size = size;
	while (*a)
	{
		chunk.mid = chunk.chunk_end - chunk_size / 2;
		process_chunk(a, b, &chunk, op);
		if (chunk.chunk_end < size - 1)
			chunk.chunk_end += chunk_size;
		else
			chunk.chunk_end = size - 1;
	}
}

void	bring_max_to_top(t_list **b, int max_pos, int b_size,
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
