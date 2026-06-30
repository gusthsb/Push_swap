/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustde-s <gustde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 18:33:01 by gustde-s          #+#    #+#             */
/*   Updated: 2026/06/03 19:23:39 by gustde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node ->content = content;
	node ->next = NULL;
	return (node);
}

// int	main(void)
// {
// 	t_list *node;
// 	node = ft_lstnew("Ola, mundo");
// 	printf("%s\n", (char *)node ->content);
// 	return (0);
// }