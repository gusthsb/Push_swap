/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustde-s <gustde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 20:22:36 by gustde-s          #+#    #+#             */
/*   Updated: 2026/06/30 20:57:45 by gustde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	reverse_rotate_a(t_list **lst_a)
{
	if (!lst_a || !(*lst_a) || !(*lst_a) -> next)
		return ;
	*lst_a = (*lst_a) -> prev;
}

void	reverse_rotate_b(t_list **lst_b)
{
	if (!lst_b || !(*lst_b) || !(*lst_b) -> next)
		return ;
	*lst_b = (*lst_b) -> prev;
}

void	rrr(t_list **lst_a, t_list **lst_b)
{
	reverse_rotate_a(lst_a);
	reverse_rotate_b(lst_b);
}
