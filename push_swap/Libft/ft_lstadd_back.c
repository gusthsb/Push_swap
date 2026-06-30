/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustde-s <gustde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 18:37:13 by gustde-s          #+#    #+#             */
/*   Updated: 2026/06/08 20:09:55 by gustde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{	
	if (!lst || !new)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
		ft_lstlast(*lst)-> next = new;
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
// 	ft_lstadd_back(&lst, ft_lstnew("Tres"));
// 	printf("%s\n", (char *)lst -> next -> next -> next -> content);
// 	return (0);
// }