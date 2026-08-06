/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustde-s <gustde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 17:11:37 by gustde-s          #+#    #+#             */
/*   Updated: 2026/07/28 16:02:30 by gustde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	swap(t_list **lst)
{
	t_list	*first;
	t_list	*second;
	t_list	*before;
	t_list	*after;

	if (!lst || !(*lst) || (*lst) -> next == *lst)
		return ;
	first = *lst;
	second = first -> next;
	if (second -> next == first)
	{
		*lst = second;
		return ;
	}
	before = first -> prev;
	after = second -> next;
	before -> next = second;
	second -> prev = before;
	second -> next = first;
	first -> prev = second;
	first -> next = after;
	after -> prev = first;
	*lst = second;
}

void	swap_a(t_list **lst_a)
{
	swap(lst_a);
	write(1, "sa\n", 3);
}

void	swap_a(t_list **lst_b)
{
	swap(lst_b);
	write(1, "sb\n", 3);
}

void swap_both(t_list **lst_a, t_list **lst_b)
{
	swap(lst_a);
	swap(lst_b);
	write(1, "ss\n", 3);
}
