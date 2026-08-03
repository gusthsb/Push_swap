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

int	is_array_duplicate(t_list *lst, int value)
{
	t_list	*current;

	if (!lst)
		return (0);
	if (lst -> content == value)
		return (1);
	current = lst -> next;
	while (current != lst)
	{
		if (current -> content == value)
			return (1);
		current = current -> next;
	}
	return (0);
}

int	ft_error(void)
{
	write(1, "Error\n", 7);
	return (7);
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
	if (valor[0] == '-')
	{
		if (valor[1] == '\0')
			return (0);
		i = 0;
	}
	while (valor[i])
	{
		if (ft_is_digit(valor[i]) == 0
			|| valor[i] > INT_MAX || valor[i] < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}

int	checking_error(char *valor)
{
	if (!is_inter(valor))
		return (0);
	// if (!is_arr_duplicate(valor))
	// 	return (0);
	return (1);
}