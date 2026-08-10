/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustde-s <gustde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 16:12:54 by gustde-s          #+#    #+#             */
/*   Updated: 2026/08/10 16:14:22 by gustde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	do_swap(t_list **lst)
{
	t_list	*first;
	t_list	*second;
	t_list	*before;
	t_list	*after;

	first = *lst;
	second = first->next;
	before = first->prev;
	after = second->next;
	before->next = second;
	second->prev = before;
	second->next = first;
	first->prev = second;
	first->next = after;
	after->prev = first;
	*lst = second;
}

void	swap_a(t_list **lst_a, op_count *op)
{
	if (!lst_a || !*lst_a || (*lst_a)->next == *lst_a)
		return ;
	if ((*lst_a)->next->next == *lst_a)
		*lst_a = (*lst_a)->next;
	else
		do_swap(lst_a);
	write(1, "sa\n", 3);
	if (op)
	{
		op -> sa++;
		op -> count++;
	}
}

void	swap_b(t_list **lst_b, op_count *op)
{
	if (!lst_b || !*lst_b || (*lst_b)->next == *lst_b)
		return ;
	if ((*lst_b)->next->next == *lst_b)
		*lst_b = (*lst_b)->next;
	else
		do_swap(lst_b);
	write(1, "sb\n", 3);
	if (op)
	{
		op->sb++;
		op->count++;
	}
}

void	swap_both(t_list **lst_a, t_list **lst_b, op_count *op)
{
	if (lst_a && *lst_a && (*lst_a)->next != *lst_a)
	{
		if ((*lst_a)->next->next == *lst_a)
			*lst_a = (*lst_a)->next;
		else
			do_swap(lst_a);
	}
	if (lst_b && *lst_b && (*lst_b)->next != *lst_b)
	{
		if ((*lst_b)->next->next == *lst_b)
			*lst_b = (*lst_b)->next;
		else
			do_swap(lst_b);
	}
	write(1, "ss\n", 3);
	if (op)
	{
		op->ss++;
		op->count++;
	}
}
