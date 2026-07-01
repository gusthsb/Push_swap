/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustde-s <gustde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 17:11:37 by gustde-s          #+#    #+#             */
/*   Updated: 2026/06/30 17:56:04 by gustde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	swap_a(t_list **lst)
{
	t_list	*first;
	t_list	*second;

	if (!lst || !(*lst) || !(*lst) -> next)
		return ;
	
	first = *lst;
	second = first -> next;
	first -> next = second -> next;
	second -> next = first;
	*lst = second;
}

void	swap_b(t_list **lst)
{
	t_list	*first;
	t_list	*second;

	if (!lst || !*lst || !(*lst) -> next)
		return ;
	
	first = *lst;
	second = first -> next;

	first -> next = second -> next;
	second -> next = first;

	*lst = second;
}

void swap_both(t_list **lst, t_list **lst2)
{
	swap_a(lst);
	swap_b(lst2);
}
