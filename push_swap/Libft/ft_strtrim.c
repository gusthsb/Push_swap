/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustde-s <gustde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 18:54:54 by gustde-s          #+#    #+#             */
/*   Updated: 2026/05/28 19:36:39 by gustde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*p;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	j = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[i]))
	{
		i++;
	}
	while (ft_strchr(set, s1[j]))
	{
		j--;
	}
	p = ft_substr(s1, i, (j - i) + 1);
	return (p);
}

// int	main(void)
// {
// 	char	str[] = "$**Ola mundo**$";
// 	char	set[] = "$*";
// 	char	*res;

// 	printf("Antes: %s\n", str);
// 	res = ft_strtrim(str, set);
// 	printf("Depois: %s\n", res);
// 	free(res);
// 	return (0);
// }