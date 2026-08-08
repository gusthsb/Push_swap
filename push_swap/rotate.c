/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustde-s <gustde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 19:44:32 by gustde-s          #+#    #+#             */
/*   Updated: 2026/08/07 17:37:38 by gustde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	rotate(t_list **lst)
{
	if (!lst || !*lst || (*lst)->next == *lst)
		return ;
	*lst = (*lst)->next;
}

void	rotate_a(t_list **lst_a)
{
	rotate(lst_a);
	write(1, "ra\n", 3);
}

void	rotate_b(t_list **lst_b)
{
	op_count	rb_count;

	rotate(lst_b);
	write(1, "rb\n", 3);
	rb_count ;
}

void	rr(t_list **lst_a, t_list **lst_b)
{
	rotate(lst_a);
	rotate(lst_b);
	write(1, "rr\n", 3);
}
