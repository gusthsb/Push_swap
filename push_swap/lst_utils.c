/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustde-s <gustde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 16:50:41 by mamatos-          #+#    #+#             */
/*   Updated: 2026/08/03 20:08:29 by gustde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	lst_size(t_list *lst) /*não precisa de ponteiro duplo quando a função só faz a leitura da lst*/
{								  /* *lst faz uma copia do ENDEREÇO de memoria, content continua sendo o original */
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
		lst = lst -> next; // Passamos de nó e armazenamos essa operação
	}
	return (size); // retornamos o tamanho da lst, baseado na quantidade de vezes que o size recebeu +1;
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
	temp = (*lst) -> prev;
	temp -> next = new;
	new -> prev = temp;
	new -> next = *lst;
	(*lst) -> prev = new;
}

t_list	*ft_lstnew(int content) // estava dando warning na compilação, mudei de void *
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list)); // não precisa de cast para o proprio tipo da var
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node -> index = 0;
	new_node->next = new_node; // apontando para o proprio no, lista circular nao aponta pra null
	new_node -> prev = new_node;
	return (new_node);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*current;
	t_list	*next;

	if (!lst || !*lst)
		return ;
	current = (*lst) -> next;
	while (current != *lst)
	{
		next = current -> next;
		free(current);
		current = next;
	}
	free(*lst);
	*lst = NULL;
}