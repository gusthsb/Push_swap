/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustde-s <gustde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 16:07:35 by gustde-s          #+#    #+#             */
/*   Updated: 2026/08/11 17:02:17 by gustde-s         ###   ########.fr       */
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

static void	push(t_list **dst, t_list **src)
{
	t_list	*moved;

	if (!src || !*src)
		return ;
	moved = *src;
	unlink_top(src);
	insert_top(dst, moved);
}

void	push_a(t_list **dst_a, t_list **src_b, t_count *op)
{
	push(dst_a, src_b);
	write(1, "pa\n", 3);
	if (op)
	{
		op -> pa++;
		op -> count++;
	}
}

void	push_b(t_list **dst_b, t_list **src_a, t_count *op)
{
	push(dst_b, src_a);
	write(1, "pb\n", 3);
	if (op)
	{
		op -> pb++;
		op -> count++;
	}
}
