/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustde-s <gustde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 17:29:08 by mamatos-          #+#    #+#             */
/*   Updated: 2026/08/11 18:55:13 by gustde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	fill_array(t_list *lst, int *arr)
{
	t_list	*current;
	int		i;

	current = lst;
	i = 0;
	while (i < lst_size(lst))
	{
		arr[i] = current->index;
		current = current->next;
		i++;
	}
	return (i);
}

static int	count_mistakes(int *arr, int size)
{
	int	mistakes;
	int	i;
	int	j;

	mistakes = 0;
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
				mistakes++;
			j++;
		}
		i++;
	}
	return (mistakes);
}

double	main_disorder(t_list *lst)
{
	int		*arr;
	int		size;
	int		mistakes;
	int		total_pairs;

	if (!lst || lst_size(lst) <= 1)
		return (0.0);
	size = lst_size(lst);
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (0.0);
	fill_array(lst, arr);
	mistakes = count_mistakes(arr, size);
	total_pairs = (size * (size - 1)) / 2;
	free(arr);
	return ((double)mistakes / (double)total_pairs);
}
