/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustde-s <gustde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 17:19:05 by gustde-s          #+#    #+#             */
/*   Updated: 2026/05/26 17:33:10 by gustde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *src, const char *find, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (find[0] == 0)
		return ((char *)src);
	while (i < size && src[i] != '\0')
	{
		j = 0;
		while (src[i + j] == find[j] && find[j] != '\0' && i + j < size)
			j++;
		if (find[j] == '\0')
			return ((char *)src + i);
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	const char	*src = "Ola, mundo";
// 	const char	*find = "mu";

// 	char *result = ft_strnstr(src, find, 12);
// 	if (result)
// 		printf("Substring encontrada: %s\n", result);
// 	else
// 		printf("Substring nao encontrada/out range.\n");	
// 	return (0);
// }