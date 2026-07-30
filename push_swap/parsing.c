#include "ft_push_swap.h"
/* Verificar se o valor está duplicado*/
// int	is_arr_duplicate(t_list *lst_a, int value)
// {
// 	t_list	*current;

// 	current = lst_a;
// 	while (current)
// 	{
// 		if (current -> content == value)
// 			return (1);
// 		current = current ->  next;
// 	}
// 	return (0);
// }

int	is_arr_duplicate(t_list *lst, int value)
{
	t_list	*current;

	if (!lst)
		return (0);
	if (lst -> content == value)
		return (1);
	current = lst -> next;
	while (current != lst)
	{
		if (current -> content == value)
			return (1);
		current = current -> next;
	}
	return (0);
}