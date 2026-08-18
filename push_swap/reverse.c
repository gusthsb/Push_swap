/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustde-s <gustde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 20:22:36 by gustde-s          #+#    #+#             */
/*   Updated: 2026/08/18 17:43:48 by gustde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	reverse(t_list **lst)
{
	if (!lst || !*lst || (*lst)->next == *lst)
		return ;
	*lst = (*lst)->prev;
}

void	reverse_rotate_a(t_list **lst_a, t_count *op)
{
	reverse(lst_a);
	print_operations("rra");
	if (op)
	{
		op->rra++;
		op->count++;
	}
}

void	reverse_rotate_b(t_list **lst_b, t_count *op)
{
	reverse(lst_b);
	print_operations("rrb");
	if (op)
	{
		op->rrb++;
		op->count++;
	}
}

void	rrr(t_list **lst_a, t_list **lst_b, t_count *op)
{
	reverse(lst_a);
	reverse(lst_b);
	print_operations("rrr");
	if (op)
	{
		op->rrr++;
		op->count++;
	}
}
