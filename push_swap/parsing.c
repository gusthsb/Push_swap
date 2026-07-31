/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamatos- <mamatos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 16:50:34 by mamatos-          #+#    #+#             */
/*   Updated: 2026/07/30 18:18:29 by mamatos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
/* Verificar se o valor está duplicado*/
// int	is_arr_duplicate(t_list *lst_a, int value)
// {
// 	t_list	*current;

// 	current = lst_a;
// 	while (current)
// 	{
// 		if (current -> content == value)
// 			return (1);
// 		current = current ->  next;
// 	}
// 	return (0);
// }

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

void	trans_arr_to_lst(t_list **lst, char **arr)
{
	t_list	*new_lst;
	t_list	*temp;
	int		i;

	if (!lst || !arr)
		return ;
	i = 1;
	while (arr[i])
	{
		new_lst = ft_lstnew(arr[i]);
		if (!new_lst)
			return ;
		ft_lstadd_back(lst, new_lst);
		i++;
	}
}
