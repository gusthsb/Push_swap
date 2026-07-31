/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamatos- <mamatos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 16:50:41 by mamatos-          #+#    #+#             */
/*   Updated: 2026/07/30 17:49:12 by mamatos-         ###   ########.fr       */
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

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
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

long	ft_atol(const char *str) // mudança nos tipo de tipo de dado, push swap pd lidar com nmr grande
{
	long	value; // long ao inves de int
	int		i;
	int		signal;

	i = 0;
	value = 0;
	signal = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signal *= -1;
		i++;
	}
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		value = value * 10 + (str[i] - 48);
		i++;
	}
	return (value * signal);
}
