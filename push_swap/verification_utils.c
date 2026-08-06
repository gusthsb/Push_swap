/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustde-s <gustde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 20:12:02 by gustde-s          #+#    #+#             */
/*   Updated: 2026/08/03 20:12:31 by gustde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	is_array_duplicate(long	*arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_error(void)
{
	write(1, "Error\n", 6);
	return (6);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_inter(char *valor)
{
	int	i;

	if (valor[0] == '\0')
		return (0);
	i = 0;
	if (valor[i] == '-' || valor[i] == '+')
		i++;
	if (valor[i] == '\0')
		return (0);
	while (valor[i])
	{
		if (ft_isdigit(valor[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	checking_error(char *str)
{
	long	value;

	if (!is_inter(str))
		return (0);
	value = ft_atol(str);
	if (value > INT_MAX || value < INT_MIN)
		return (0);
	return (1);
}