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
		return ;
	}
	temp = *lst;
	while (temp -> next != *lst) //pra quando chegar no ultimo no (que aponta pra cbç)
		temp = temp -> next;
	temp -> next = new;
	new -> next = *lst; //o ultimo do new aponta pra cbç
}

t_list	*ft_lstnew(int content) // estava dando warning na compilação, mudei de void *
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list)); // não precisa de cast para o proprio tipo da var
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = new_node; // apontando para o proprio no, lista circular nao aponta pra null
	return (new_node);
}
