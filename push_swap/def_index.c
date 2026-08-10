/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamatos- <mamatos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 17:38:55 by mamatos-          #+#    #+#             */
/*   Updated: 2026/08/10 17:38:56 by mamatos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	sort_array(int *array, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size)
	{
		j = i;
		while (j > 0 && array[j - 1] > array[j])
		{
			temp = array[j - 1];
			array[j - 1] = array[j];
			array[j] = temp;
			j--;
		}
		i++;
	}
}

static int	find_rank(int *sorted, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (sorted[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

static void	fill_sorted(t_list *lst_a, int *sorted, int size)
{
	t_list	*current;
	int		i;

	current = lst_a;
	i = 0;
	while (i < size)
	{
		sorted[i] = current -> content;
		current = current -> next;
		i++;
	}
}

static void	fill_indexes(t_list *lst_a, int *sorted, int size)
{
	t_list	*current;
	int		i;

	current = lst_a;
	i = 0;
	while (i < size)
	{
		current -> index = find_rank(sorted, size, current -> content);
		current = current -> next;
		i++;
	}
}

void	set_stack_indexes(t_list *lst_a)
{
	int		size;
	int		*sorted;

	size = lst_size(lst_a);
	sorted = malloc(sizeof(int) * size);
	if (!sorted)
		return ;
	fill_sorted(lst_a, sorted, size);
	sort_array(sorted, size);
	fill_indexes(lst_a, sorted, size);
	free(sorted);
}
