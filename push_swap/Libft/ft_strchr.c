/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustde-s <gustde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 18:43:53 by gustde-s          #+#    #+#             */
/*   Updated: 2026/05/25 19:04:51 by gustde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t			i;
	unsigned char	find;

	i = 0;
	find = (unsigned char)c;
	while (str[i])
	{
		if (str[i] == find)
			return ((char *)str + i);
		i++;
	}
	if (find == '\0')
		return ((char *)str + i);
	return (NULL);
}

// int	main(void)
// {
// 	char str[40] = "Ola, mundo";
// 	char letter;

// 	letter = 'a';
// 	if (ft_strchr(str, letter) != NULL)
// 		printf("Foi encontrado (%c) na str\n", letter);
// 	else
// 		printf("Não foi encontrado (%c) na str\n", letter);
// 	return (0);
// }