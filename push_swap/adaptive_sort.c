#include "ft_push_swap.h"

void	sort_adaptive(t_list **stack_a, t_list **stack_b, t_count *op)
{
	double	disorder;
	int		size;

	size = lst_size(*stack_a);
	if (size <= 5)
	{
		sort_simple(stack_a, stack_b, op);
		return ;
	}
	disorder = main_disorder(*stack_a);
	if (disorder < 0.2)
		sort_simple(stack_a, stack_b, op);
	else if (disorder < 0.5)
		sort_medium(stack_a, stack_b, op);
	else
		sort_complex(stack_a, stack_b, op);
}
