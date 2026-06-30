/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustde-s <gustde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 18:33:21 by gustde-s          #+#    #+#             */
/*   Updated: 2026/05/28 18:54:24 by gustde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_strs;
	char	*memaloc;

	if (!s1 || !s2)
		return (NULL);
	len_strs = ft_strlen(s1) + (ft_strlen(s2) + 1);
	memaloc = (char *)malloc(len_strs);
	if (!memaloc)
		return (NULL);
	ft_strlcpy(memaloc, s1, ft_strlen(s1) + 1);
	ft_strlcat(memaloc, s2, len_strs);
	return (memaloc);
}

// int	main(void)
// {
// 	char	str1[] = "Ola ";
// 	char	str2[] = "mundo";
// 	char	*res;

// 	printf("Antes, str1 = %s   str2 = %s\n", str1, str2);
// 	res = ft_strjoin(str1, str2);
// 	printf("Depois  %s\n", res);
// 	free (res);
// 	return (0);
// }