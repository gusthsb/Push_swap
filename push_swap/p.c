/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustde-s <gustde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 17:56:53 by gustde-s          #+#    #+#             */
/*   Updated: 2026/06/30 20:22:04 by gustde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	push_a(t_list **lst_b, t_list **lst_a)
{
	t_list	*top_b;

	if (!lst_b || !*lst_b)
		return ;
		
	top_b = *lst_b;
	*lst_b = top_b -> next;
	top_b -> next = *lst_a;
	*lst_a = top_b;
}

void	push_b(t_list **lst_a, t_list **lst_b)
{
	t_list	*top_a;

	if (!lst_a || !*lst_a)
		return ;
		
	top_a = *lst_a;
	*lst_a = top_a -> next;
	top_a -> next = *lst_b;
	*lst_b = top_a;
}
