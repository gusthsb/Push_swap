/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustde-s <gustde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 19:12:06 by gustde-s          #+#    #+#             */
/*   Updated: 2026/05/25 19:37:08 by gustde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t			i;
	unsigned char	find;
	char			*last;

	i = 0;
	find = (unsigned char )c;
	last = NULL;
	while (str[i])
	{
		if (str[i] == find)
			last = (char *)str + i;
		i++;
	}
	if (find == '\0')
		return ((char *)str + i);
	return (last);
}

// int	main(void)
// {
// 	char	str[] = "Macacaco";
// 	char	*result;

// 	result = ft_strrchr(str, 'a');
// 	if (result)
// 		printf("Ultimo char 'a': %s\n", result);
// 	result = ft_strrchr(str, 'z');
// 	if (result == NULL)
// 		printf("'x' não encontrado\n");
// 	return (0);
// }