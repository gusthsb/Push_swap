/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustde-s <gustde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 20:22:36 by gustde-s          #+#    #+#             */
/*   Updated: 2026/08/10 16:17:12 by gustde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	reverse(t_list **lst)
{
	if (!lst || !*lst || (*lst)->next == *lst)
		return ;
	*lst = (*lst)->prev;
}

void	reverse_rotate_a(t_list **lst_a, op_count *op)
{
	reverse(lst_a);
	write(1, "rra\n", 4);
	if (op)
	{
		op->rra++;
		op->count++;
	}
}

void	reverse_rotate_b(t_list **lst_b, op_count *op)
{
	reverse(lst_b);
	write(1, "rrb\n", 4);
	if (op)
	{
		op->rrb++;
		op->count++;
	}
}

void	rrr(t_list **lst_a, t_list **lst_b, op_count *op)
{
	reverse(lst_a);
	reverse(lst_b);
	write(1, "rrr\n", 4);
	if (op)
	{
		op->rrr++;
		op->count++;
	}
}
