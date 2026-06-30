/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustde-s <gustde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 16:53:56 by gustde-s          #+#    #+#             */
/*   Updated: 2026/06/05 18:34:58 by gustde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst -> next != NULL)
	{
		lst = lst -> next;
	}
	return (lst);
}

// int	main(void)
// {
// 	t_list	*lst;
// 	lst = ft_lstnew("Dois");
// 	ft_lstadd_front(&lst, ft_lstnew("Um"));
// 	ft_lstadd_front(&lst, ft_lstnew("Zero"));
// 	printf("%s\n", (char *)lst -> content);
// 	printf("%s\n", (char *)lst -> next -> content);
// 	printf("%s\n", (char *)lst -> next -> next -> content);
// 	printf("Qnt de no: %d\n", ft_lstsize(lst));
// 	printf("Ultimo nó: %s\n", (char *)ft_lstlast(lst)->content);
// 	return (0);
// }