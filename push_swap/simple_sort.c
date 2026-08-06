#include "ft_push_swap.h"

static void	two_sorted(t_list **lst)
{
	if ((*lst) -> content > (*lst) -> next -> content)
		swap_a(lst);
}

static void	three_sorted(t_list **lst)
{
	int	first;
	int	second;
	int	third;

	first = (*lst) -> index;
	second = (*lst) -> next -> index;
	third = (*lst) -> next -> next -> index;
	if (first > second && second > third)
	{
		swap_a(lst);
		reverse_rotate_a(lst);
	}
	else if (first > third && third < second)
		rotate_a(lst);
	else if (second > first && first >third)
		reverse_rotate_a(lst);
	else if (second > third && third > first)
	{
		swap_a(lst);
		rotate_a(lst);
	}
	else if (third > first && first > second)
		swap_a(lst);
}

static int	min_position(t_list **lst)
{
	t_list	*current;
	int		min_index;
	int		pos;
	int		i;
	int		size;

	current = *lst;
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

static void	rotate_to_top(t_list **stack_a, int pos, int size)
{
	if (pos <= size / 2)
	{
		while (pos > 0)
		{
			rotate_a(stack_a);
			pos--;
		}
	}
	else
	{
		while (pos < size)
		{
			reverse_rotate_a(stack_a);
			pos++;
		}
	}
}