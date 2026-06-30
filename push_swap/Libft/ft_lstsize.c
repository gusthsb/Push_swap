/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustde-s <gustde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 16:38:17 by gustde-s          #+#    #+#             */
/*   Updated: 2026/06/05 16:52:40 by gustde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	if (!lst)
		return (0);
	i = 0;
	while (lst != NULL)
	{
		lst = lst ->next;
		i++;
	}
	return (i);
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
// 	return (0);
// }