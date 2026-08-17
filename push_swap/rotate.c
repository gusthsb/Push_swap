/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamatos- <mamatos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 19:44:32 by gustde-s          #+#    #+#             */
/*   Updated: 2026/08/10 17:43:49 by mamatos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	rotate(t_list **lst)
{
	if (!lst || !*lst || (*lst)->next == *lst)
		return ;
	*lst = (*lst)->next;
}

void	rotate_a(t_list **lst_a, t_count *op)
{
	rotate(lst_a);
	write(1, "ra\n", 3);
	if (op)
	{
		op->ra++;
		op->count++;
	}
}

void	rotate_b(t_list **lst_b, t_count *op)
{
	rotate(lst_b);
	write(1, "rb\n", 3);
	if (op)
	{
		op->rb++;
		op->count++;
	}
}

void	rr(t_list **lst_a, t_list **lst_b, t_count *op)
{
	rotate(lst_a);
	rotate(lst_b);
	write(1, "rr\n", 3);
	if (op)
	{
		op->rr++;
		op->count++;
	}
}
