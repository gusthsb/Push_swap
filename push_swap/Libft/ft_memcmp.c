/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustde-s <gustde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 16:58:54 by gustde-s          #+#    #+#             */
/*   Updated: 2026/05/26 17:14:22 by gustde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *pont1, const void *pont2, size_t cmp)
{
	size_t			i;
	unsigned char	*p1;
	unsigned char	*p2;

	i = 0;
	p1 = (unsigned char *)pont1;
	p2 = (unsigned char *)pont2;
	if (cmp == 0)
		return (0);
	while (p1[i] == p2[i] && i < cmp - 1)
	{
		i++;
	}
	return (p1[i] - p2[i]);
}

// int main(void)
// {
//     char    s1[] = "Ola, mundo";
//     char    s2[] = "Ola, mundo";
//     char    s3[] = "Ola, xxxxx";

//     printf("Iguais:     %d\n", ft_memcmp(s1, s2, 11));
//     printf("Diferentes: %d\n", ft_memcmp(s1, s3, 11));
//     printf("cmp = 0:      %d\n", ft_memcmp(s1, s3, 0));
//     printf("cmp = 5:      %d\n", ft_memcmp(s1, s3, 5));
//     return (0);
// }