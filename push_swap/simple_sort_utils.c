/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamatos- <mamatos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 17:27:00 by mamatos-          #+#    #+#             */
/*   Updated: 2026/08/10 17:43:43 by mamatos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	two_sorted(t_list **lst, t_count *op)
{
	if ((*lst)->index > (*lst)-> next->index)
		swap_a(lst, op);
}

void	three_sorted(t_list **lst, t_count *op)
{
	int	first;
	int	second;
	int	third;

	first = (*lst)-> index;
	second = (*lst)-> next->index;
	third = (*lst)-> next -> next -> index;
	if (first < second && second < third)
		return ;
	if (first > second && second < third && first < third)
		swap_a(lst, op);
	else if (first > second && second < third && first > third)
		rotate_a(lst, op);
	else if (first < second && second > third && first > third)
		reverse_rotate_a(lst, op);
	else if (first < second && second > third && first < third)
	{
		swap_a(lst, op);
		rotate_a(lst, op);
	}
	else if (first > second && second > third)
	{
		swap_a(lst, op);
		reverse_rotate_a(lst, op);
	}
}

int	min_position(t_list *lst)
{
	t_list	*current;
	int		min_index;
	int		pos;
	int		i;
	int		size;

	current = lst;
	min_index = current -> index;
	pos = 0;
	i = 0;
	size = lst_size(lst);
	while (i < size)
	{
		if (current -> index < min_index)
		{
			min_index = current -> index;
			pos = i;
		}
		current = current -> next;
		i++;
	}
	return (pos);
}

void	rotate_to_top(t_list **stack_a, int pos, int size, t_count *op)
{
	if (pos * size / 2)
	{
		while (pos > 0)
		{
			rotate_a(stack_a, op);
			pos--;
		}
	}
	else
	{
		while (pos < size)
		{
			reverse_rotate_a(stack_a, op);
			pos++;
		}
	}
}

void	min_to_b(t_list **stack_a, t_list **stack_b, t_count *op)
{
	int	pos;
	int	size;

	size = lst_size(*stack_a);
	pos = min_position(*stack_a);
	rotate_to_top(stack_a, pos, size, op);
	push_b(stack_b, stack_a, op);
}
