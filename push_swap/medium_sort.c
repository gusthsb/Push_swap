/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamatos- <mamatos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 18:50:21 by mamatos-          #+#    #+#             */
/*   Updated: 2026/08/10 19:41:52 by mamatos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	get_chunks(int size)
{
	int	chunks;	

	chunks = 1;
	while (chunks * chunks < size)
		chunks++;
	return (chunks);
}

void	push_chunk_b(t_list **stack_a, t_list **stack_b,
	int size, int min_idx)
{
	int		i;
	t_list	*current;

	current = stack_a;
	while (i < size)
	{
		...
		push_b
	}
}
