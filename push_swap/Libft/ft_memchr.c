/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustde-s <gustde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 16:43:37 by gustde-s          #+#    #+#             */
/*   Updated: 2026/05/26 16:58:18 by gustde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *pont, int ch, size_t size)
{
	size_t			i;
	unsigned char	find;
	unsigned char	*p;

	i = 0;
	find = (unsigned char )ch;
	p = (unsigned char *)pont;
	while (i < size)
	{
		if (p[i] == find)
			return ((void *)p + i);
		i++;
	}
	return (NULL);
}

// int main(void)
// {
//     char    str[] = "Ola, mundo";
//     char    *result;

//     result = ft_memchr(str, 'a', 11);
//     if (result)
//         printf("Achou: %s\n", (char *)result);
//     else
//         printf("Nao achou\n");
//     result = ft_memchr(str, '4', 11);
//     if (result)
//         printf("Achou: %s\n", (char *)result);
//     else
//         printf("Nao achou '4'\n");
//     return (0);
// }