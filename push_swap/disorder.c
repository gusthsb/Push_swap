/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamatos- <mamatos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 17:29:08 by mamatos-          #+#    #+#             */
/*   Updated: 2026/08/10 17:39:19 by mamatos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	*trans(t_list *lst_en, int *size)
{
	int		*new_lst;
	int		i;
	t_list	*current;

	if (!lst_en)
		return (NULL);
	*size = lst_size(lst_en);
	new_lst = malloc(sizeof(int) * (*size));
	if (!new_lst)
		return (NULL);
	i = 0;
	current = lst_en;
	while (i < *size)
	{
		new_lst[i] = current -> content;
		current = current -> next;
		i++;
	}
	return (new_lst);
}

static double	calculate_disorder(int *lst_a, int size)
{
	double	mistakes;
	double	total_pairs;
	int		i;
	int		j;

	mistakes = 0;
	total_pairs = 0;
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			total_pairs++;
			if (lst_a[i] > lst_a[j])
				mistakes++;
			j++;
		}
		i++;
	}
	if (total_pairs == 0)
		return (0.0);
	return (mistakes / total_pairs);
}

double	main_disorder(t_list *lst)
{
	int		*new_arr;
	double	value;
	int		size;

	new_arr = trans(lst, &size);
	if (!new_arr)
		return (0.0);
	value = calculate_disorder(new_arr, lst_size(lst));
	free(new_arr);
	return (value);
}
