/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustde-s <gustde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 17:53:46 by gustde-s          #+#    #+#             */
/*   Updated: 2026/05/28 18:31:06 by gustde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	i;
	char	*rest;

	rest = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	i = 0;
	if (rest == NULL)
		return (NULL);
	while (src[i])
	{
		rest[i] = src[i];
		i++;
	}
	rest[i] = '\0';
	return (rest);
}

// int main(void)
// {
//     char    *copy;
//     char    *copy2;

//     copy = ft_strdup("Oie");
//     if (copy == NULL)
//         return (1);
//     printf("copy:  %s\n", copy);
//     copy2 = ft_strdup(copy);
//     if (copy2 == NULL)
//     {
//         free(copy);
//         return (1);
//     }
//     printf("copy2: %s\n", copy2);

//     free(copy);
//     free(copy2);
//     return (0);
// }