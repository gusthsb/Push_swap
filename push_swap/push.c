/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustde-s <gustde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 17:56:53 by gustde-s          #+#    #+#             */
/*   Updated: 2026/07/28 16:36:25 by gustde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	unlink_top(t_list **src)
{
	t_list	*moved;

	moved = *src;
	if (moved->next == moved)
		*src = NULL;
	else
	{
		moved->prev->next = moved->next;
		moved->next->prev = moved->prev;
		*src = moved->next;
	}
}

static void	insert_top(t_list **dst, t_list *moved)
{
	if (!*dst)
	{
		moved->next = moved;
		moved->prev = moved;
	}
	else
	{
		moved->next = *dst;
		moved->prev = (*dst)->prev;
		(*dst)->prev->next = moved;
		(*dst)->prev = moved;
	}
	*dst = moved;
}

void	push_a(t_list **dst_a, t_list **src_b)
{
	t_list	*moved;

	if (!src_b || !(*src_b))
		return ;
	moved = *src_b;
	unlink_top(src_b);
	insert_top(dst_a, moved);
}

void	push_b(t_list **dst_b, t_list **src_a)
{
	t_list	*moved;

	if (!src_a || !(*src_a))
		return ;
	moved = *src_a;
	unlink_top(src_a);
	insert_top(dst_b, moved);
}
