#include "ft_push_swap.h"

static void	two_sorted(t_list **lst)
{
	if ((*lst) -> content > (*lst) -> next -> content)
		swap_a(lst);
}