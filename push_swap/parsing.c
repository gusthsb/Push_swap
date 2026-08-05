/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustde-s <gustde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 16:50:34 by mamatos-          #+#    #+#             */
/*   Updated: 2026/08/03 20:11:49 by gustde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	trans_arr_to_lst(t_list **lst, char **arr)
{
	t_list	*new_lst;
	int		i;

	if (!lst || !arr)
		return ;
	i = 1;
	while (arr[i])
	{
		new_lst = ft_lstnew((int)ft_atol(arr[i])); // ja convertemos aqui e adicionamos na lst
		if (!new_lst)
			return;
		ft_lstadd_back(lst, new_lst);
		i++;
	}
}

long	ft_atol(const char *str)
{
	long	value;
	int		i;
	int		signal;

	i = 0;
	value = 0;
	signal = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signal = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (value > ((long)INT_MAX + 1) / 10)
			return ((long)INT_MAX + 1);
		value = value * 10 + (str[i] - '0');
		if (value > (long)INT_MAX + 1)
			return ((long)INT_MAX + 1);
		i++;
	}
	return (value * signal);
}
