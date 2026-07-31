/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustde-s <gustde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 19:44:32 by gustde-s          #+#    #+#             */
/*   Updated: 2026/07/28 15:39:01 by gustde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
void	rotate_a(t_list **lst_a)
{
	if (!lst_a || !(*lst_a) || !(*lst_a) -> next)
		return ;
	*lst_a = (*lst_a) -> next;
}

void	rotate_b(t_list **lst_b)
{
	if (!lst_b || !(*lst_b) || !(*lst_b) -> next)
		return ;
	*lst_b = (*lst_b) -> next;
}

void	rr(t_list **lst_a, t_list **lst_b)
{
	rotate_a(lst_a);
	rotate_b(lst_b);
}
