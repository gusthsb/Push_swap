/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustde-s <gustde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 19:26:34 by gustde-s          #+#    #+#             */
/*   Updated: 2026/06/05 19:49:16 by gustde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst -> content);
		lst = lst -> next;
	}
}

// void	print_content(void *content)
// {
// 	printf("%s\n", (char *)content);
// }
// int main(void)
// {
//     t_list *lst;
//     lst = ft_lstnew("Zero");
//     ft_lstadd_back(&lst, ft_lstnew("Um"));
//     ft_lstadd_back(&lst, ft_lstnew("Dois"));
//     ft_lstiter(lst, print_content);
//     return (0);
// }