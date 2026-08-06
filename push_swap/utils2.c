/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustde-s <gustde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 17:08:09 by mamatos-          #+#    #+#             */
/*   Updated: 2026/08/03 20:02:39 by gustde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int count_numbers(const char **str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

long	*trans_a_to_long(const char **str)
{
	int		i;
	long	*new_arr;

	if (!str || !*str)
		return (NULL);
	new_arr = malloc(sizeof(long) * count_numbers(str));
	if (!new_arr)
		return (NULL);
	i = 0;
	while (str[i])
	{
		new_arr[i] = ft_atol(str[i]);
		i++;
	}
	return (new_arr);
}

int		is_sorted(t_list *lst)
{
	t_list	*start;
	t_list	*current;

	if (!lst || lst_size(lst) <= 1)
		return (1);
	start = lst;
	current = lst;
	while (current -> next != start)
	{
		if (current -> content > current -> next -> content)
			return (0);
		current = current -> next;
	}
	return (1);
}