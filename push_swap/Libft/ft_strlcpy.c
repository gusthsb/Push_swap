/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustde-s <gustde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 15:49:40 by gustde-s          #+#    #+#             */
/*   Updated: 2026/05/25 16:13:24 by gustde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t count)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	if (count == 0)
		return (src_len);
	while (src[i] != '\0' && i < count - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_len);
}
// int main(void)
// {
// 	char	src[40] = "Olá, mundo";
// 	char	dest[40];
// 	size_t	ret;

// 	ret = ft_strlcpy(dest, src, 12);
// 	printf("Dest: %s  |  ret: %zu\n", dest, ret);
// 	return (0);
// }