#include "ft_push_swap.h"

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
