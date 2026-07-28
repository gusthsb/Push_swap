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

void	swap_a(t_list **lst_a)
{
	t_list	*first;
	t_list	*second;
	t_list	*before;
	t_list	*after;

	if (!lst_a || !(*lst_a) || (*lst_a) -> next == *lst_a)
		return ;
	/* !lst_a - checa se o endereço da stack que passamos é null
	   !(*lst_a) checa se a stack é null
		(*lst_a) -> next == *lst_a  -- checa se a stack tem apenas um nó existente */
	first = *lst_a;
	second = first -> next;
	if (second -> next == first)
	{
		*lst_a = second;
		return ;
	}
	/* Tratando caso especial, se a stack só tiver 2 elementos, só fazemos
	   cabeça virar o segundo nó da lst */
	before = first -> prev;
	after = second -> next;
	before -> next = second;
	second -> prev = before;
	second -> next = first;
	first -> prev = second;
	first -> next = after;
	after -> prev = first;
	*lst_a = second;
}

void	swap_b(t_list **lst_b)
{
	t_list	*first;
	t_list	*second;
	t_list	*before;
	t_list	*after;

	if (!lst_b || !(*lst_b) || (*lst_b) -> next == *lst_b)
		return ;
	first = *lst_b;
	second = first -> next;
	if (second -> next == first)
	{
		*lst_b = second;
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
	*lst_b = second;
}

void swap_both(t_list **lst, t_list **lst2)
{
	swap_a(lst);
	swap_b(lst2);
}
