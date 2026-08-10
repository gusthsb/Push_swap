/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamatos- <mamatos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 16:50:41 by mamatos-          #+#    #+#             */
/*   Updated: 2026/08/10 17:46:01 by mamatos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	lst_size(t_list *lst)
{
	int		size;
	t_list	*start;

	if (!lst)
		return (0);
	size = 1;
	start = lst;
	lst = lst -> next;
	while (lst != start)
	{
		size++;
		lst = lst -> next;
	}
	return (size);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		new -> next = new;
		new -> prev = new;
		return ;
	}
	temp = (*lst)-> prev;
	temp -> next = new;
	new -> prev = temp;
	new -> next = *lst;
	(*lst)-> prev = new;
}

t_list	*ft_lstnew(int content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node -> index = 0;
	new_node->next = new_node;
	new_node -> prev = new_node;
	return (new_node);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*current;
	t_list	*next;

	if (!lst || !*lst)
		return ;
	current = (*lst)-> next;
	while (current != *lst)
	{
		next = current -> next;
		free(current);
		current = next;
	}
	free(*lst);
	*lst = NULL;
}
