/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustde-s <gustde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 20:22:36 by gustde-s          #+#    #+#             */
/*   Updated: 2026/06/30 20:57:45 by gustde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	reverse_rotate_a(t_list **lst_a)
{
	t_list	*new_first;
	t_list	*old_last;

	if (!lst_a || !(*lst_a) || !(*lst_a) -> next)
		return ;
	old_last = *lst_a;
	while (old_last -> next -> next != NULL)
		old_last = old_last -> next;
	new_first = old_last->next;
	old_last -> next = NULL;
	new_first -> next = *lst_a;
	*lst_a = new_first;
}

void	reverse_rotate_b(t_list **lst_b)
{
	t_list	*new_first;
	t_list	*old_last;

	if (!lst_b || !(*lst_b) || !(*lst_b) -> next)
		return ;
	old_last = *lst_b;
	while (old_last -> next -> next != NULL)
		old_last = old_last -> next;
	new_first = old_last -> next;
	old_last -> next = NULL;
	new_first -> next = *lst_b;
	*lst_b = new_first;
}

void	rrr(t_list **lst_a, t_list **lst_b)
{
	reverse_rotate_a(lst_a);
	reverse_rotate_b(lst_b);
}

/* somente mudança de nome de variavel 
   penultimate -> new_first
   last -> old_last
*/