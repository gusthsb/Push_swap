/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustde-s <gustde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 17:07:26 by gustde-s          #+#    #+#             */
/*   Updated: 2026/06/03 17:32:29 by gustde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f) (unsigned int, char *))
{
	unsigned int	i;
	size_t			len;

	if (s == 0)
		return ;
	len = ft_strlen(s);
	i = 0;
	while (i < len)
	{
		f (i, &s[i]);
		i++;
	}
}

// void    to_upper(unsigned int i, char *c)
// {
// 	(void)i;
// 	*c = ft_toupper(*c);
// }
// int	main(void)
// {
// 	char	str[] = "Ola, mundo";	
// 	printf("Antes: %s\n", str);
// 	ft_striteri(str, to_upper);
// 	printf("Depois: %s\n", str);
// 	return (0);
// }