/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustde-s <gustde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 15:22:40 by gustde-s          #+#    #+#             */
/*   Updated: 2026/06/08 20:09:31 by gustde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t count)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	i = 0;
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (d < s)
	{
		while (i < count)
		{
			d[i] = s[i];
			i++;
		}
	}
	else if (d > s)
	{
		i = count;
		while (i > 0)
		{
			i--;
			d[i] = s[i];
		}
	}
	return (dest);
}

// int	main(void)
// {
// 	char	src[] = "Olá, mundo";
// 	char	dest[40];
// 	printf("Dest = %s\n", (char *)ft_memmove(dest, src, 12));	
// 	return (0);
// }