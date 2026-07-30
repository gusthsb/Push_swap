#include "ft_push_swap.h"

int	is_arr_duplicate(t_list *lst_a, int value)
{
	t_list	*current;

	current = lst_a;
	while (current)
	{
		if (current -> content == value)
			return (1);
		current = current ->  next;
	}
	return (0);
}
