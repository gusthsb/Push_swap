/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamatos- <mamatos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 20:22:36 by gustde-s          #+#    #+#             */
/*   Updated: 2026/07/30 17:54:47 by mamatos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	reverse(t_list **lst)
{
	if (!lst || !*lst || (*lst)->next == *lst)
		return ;
	*lst = (*lst)->prev;
}

void	reverse_rotate_a(t_list **lst_a)
{
	reverse(lst_a);
	write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_list **lst_b)
{
	reverse(lst_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_list **lst_a, t_list **lst_b)
{
	reverse(lst_a);
	reverse(lst_b);
	write(1, "rrr\n", 4);
}
