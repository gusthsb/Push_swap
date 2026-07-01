/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustde-s <gustde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 17:56:53 by gustde-s          #+#    #+#             */
/*   Updated: 2026/06/30 20:22:04 by gustde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	push_a(t_list **dst_a, t_list **src_b)
{
	t_list	*moved;

	if (!src_b || !*src_b)
		return ;
	moved = *src_b;
	*src_b = moved->next;
	moved->next = *dst_a;
	*dst_a = moved;
}

void	push_b(t_list **dst_b, t_list **src_a)
{
	t_list	*moved;

	if (!src_a || !*src_a)
		return ;
	moved = *src_a;
	*src_a = moved->next;
	moved->next = *dst_b;
	*dst_b = moved;
}

/* mudança de nomes de variavel e de parametros - 
   parametros = lst_a e lst_b para dst_a/b e src_a/b 
   variaveis  = top_a/b para moved
*/