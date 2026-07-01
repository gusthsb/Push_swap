/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustde-s <gustde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 19:44:32 by gustde-s          #+#    #+#             */
/*   Updated: 2026/06/30 20:22:41 by gustde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	rotate_a(t_list **lst_a)
{
	t_list	*first;
	t_list	*last;

	if (!lst_a || !(*lst_a) || !(*lst_a) -> next)
		return ;
	
	first = *lst_a;
	last = *lst_a;
	while (last -> next != NULL)
		last = last -> next;
	*lst_a = first -> next;
	first -> next = NULL;
	last -> next = first;
}

void	rotate_b(t_list **lst_b)
{
	t_list	*first;
	t_list	*last;

	if (!lst_b || !(*lst_b) || !(*lst_b) -> next)
		return ;

	first = *lst_b;
	last = *lst_b;
	while (last -> next != NULL)
		last = last -> next;
	*lst_b = first -> next;
	first -> next = NULL;
	last -> next = first;
}

void	rr(t_list **lst_a, t_list **lst_b)
{
	rotate_a(lst_a);
	rotate_b(lst_b);
}
