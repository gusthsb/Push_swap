/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustde-s <gustde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 19:50:18 by gustde-s          #+#    #+#             */
/*   Updated: 2026/06/08 17:13:38 by gustde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	t_list	*new_lst;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		node = ft_lstnew(f(lst -> content));
		if (!node)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}	
		ft_lstadd_back(&new_lst, node);
		lst = lst -> next;
	}
	return (new_lst);
}

// void	*map_to_upper(void *content)
// {
// 	char	*str;
// 	char	*new_str;
// 	int		i;

// 	if (!content)
// 		return (NULL);
// 	str = (char *)content;
// 	new_str = ft_strdup(str);
// 	if (!new_str)
// 		return (NULL);
// 	i = 0;
// 	while (new_str[i])
// 	{
// 		if (new_str[i] >= 'a' && new_str[i] <= 'z')
// 			new_str[i] -= 32;
// 		i++;
// 	}
// 	return ((void *)new_str);
// }

// void	del_content(void *content)
// {
// 	free(content);
// }

// void	print_list(t_list *lst, char *nome_lista)
// {
// 	printf("%s: ", nome_lista);
// 	while (lst)
// 	{
// 		printf("[%s] -> ", (char *)lst->content);
// 		lst = lst->next;
// 	}
// 	printf("NULL\n");
// }

// int	main(void)
// {
// 	t_list	*lista_original;
// 	t_list	*lista_mapeada;
// 	t_list	*node1;
// 	t_list	*node2;
// 	t_list	*node3;

// 	node1 = ft_lstnew(ft_strdup("ola"));
// 	node2 = ft_lstnew(ft_strdup("mundo"));
// 	node3 = ft_lstnew(ft_strdup("xd"));

// 	lista_original = node1;
// 	ft_lstadd_back(&lista_original, node2);
// 	ft_lstadd_back(&lista_original, node3);

// 	printf("--- ANTES DO MAP ---\n");
// 	print_list(lista_original, "Lista Original");

// 	lista_mapeada = ft_lstmap(lista_original, map_to_upper, del_content);

// 	printf("\n--- DEPOIS DO MAP ---\n");
// 	print_list(lista_original, "Lista Original (deve estar intocada)");
// 	print_list(lista_mapeada, "Lista Mapeada (deve estar MAIÚSCULA)");

// 	ft_lstclear(&lista_original, del_content);
// 	ft_lstclear(&lista_mapeada, del_content);

// 	return (0);
// }