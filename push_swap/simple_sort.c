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

static void	min_to_b(t_list **stack_a, t_list **stack_b)
{
	int	pos;
	int	size;

	size = lst_size(*stack_a);
	pos = min_position(*stack_a);
	rotate_to_top(stack_a, pos, size);
	push_b(stack_b, stack_a);
}

void	sort_simple(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = lst_size(*stack_a);
	if (size == 2)
		two_sorted(stack_a);
	else if (size == 3)
		three_sorted(stack_a);
	else if (size <= 5)
	{
		while (lst_size(*stack_a) > 3)
			min_to_b(stack_a, stack_b);
		three_sorted(stack_a);
		while (*stack_b)
			push_a(stack_a, stack_b);
	}
}
