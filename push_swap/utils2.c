/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamatos- <mamatos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 17:08:09 by mamatos-          #+#    #+#             */
/*   Updated: 2026/08/03 18:01:55 by mamatos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int count_numbers(char **str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

long	*trans_a_to_long(char **str)
{
	int		i;
	long	*new_arr;

	if (!str)
		return (0);
	new_arr = malloc(sizeof(long) * count_numbers(str));
	if (!new_arr)
		return (0);
	i = 0;
	while (str[i])
	{
		new_arr[i] = ft_atol(str[i]);
		i++;
	}
	return (new_arr);
}
