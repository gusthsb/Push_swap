/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustde-s <gustde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 18:24:16 by gustde-s          #+#    #+#             */
/*   Updated: 2026/06/08 20:09:20 by gustde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	unsigned char	*temp;
	size_t			i;

	i = 0;
	if (num != 0 && (num * size) / num != size)
		return (NULL);
	temp = (unsigned char *)malloc(num * size);
	if (!temp)
		return (NULL);
	while (i < num * size)
	{
		temp[i] = 0;
		i++;
	}
	return (temp);
}

// int	main(void)
// {
// 	int		i;
// 	char	*str;
// 	i = 0;
// 	str = (char *)ft_calloc(5, sizeof(char));
// 	while (i < 5)
// 	{
// 		printf("str[%d] = %d\n", i, str[i]);
// 		i++;
// 	}
// 	free(str);
// 	str = NULL;
// 	return (0);
// }