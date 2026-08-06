#include "ft_push_swap.h"

static void	do_swap(t_list **lst)
{
	t_list	*first;
	t_list	*second;
	t_list	*before;
	t_list	*after;

	first = *lst;
	second = first->next;
	before = first->prev;
	after = second->next;
	before->next = second;
	second->prev = before;
	second->next = first;
	first->prev = second;
	first->next = after;
	after->prev = first;
	*lst = second;
}

void	swap_a(t_list **lst_a)
{
	if (!lst_a || !*lst_a || (*lst_a)->next == *lst_a)
		return ;
	if ((*lst_a)->next->next == *lst_a)
		*lst_a = (*lst_a)->next;
	else
		do_swap(lst_a);
	write(1, "sa\n", 3);
}

void	swap_b(t_list **lst_b)
{
	if (!lst_b || !*lst_b || (*lst_b)->next == *lst_b)
		return ;
	if ((*lst_b)->next->next == *lst_b)
		*lst_b = (*lst_b)->next;
	else
		do_swap(lst_b);
	write(1, "sb\n", 3);
}

void	swap_both(t_list **lst_a, t_list **lst_b)
{
	if (lst_a && *lst_a && (*lst_a) -> next != *lst_a)
	{
		if ((*lst_a) -> next->next == *lst_a)
			*lst_a = (*lst_a)->next;
		else
			do_swap(lst_a);
	}
	if (lst_b && *lst_b && (*lst_b)->next != *lst_b)
	{
		if ((*lst_b)->next->next == *lst_b)
			*lst_b = (*lst_b)->next;
		else
			do_swap(lst_b);
	}
	write(1, "ss\n", 3);
}
