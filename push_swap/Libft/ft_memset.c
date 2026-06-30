/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustde-s <gustde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 15:59:44 by gustde-s          #+#    #+#             */
/*   Updated: 2026/05/21 15:39:48 by gustde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *a, int c, size_t len)
{
	unsigned char	*temp;

	temp = (unsigned char *) a;
	while (len > 0)
	{
		*temp++ = (unsigned char) c;
		len --;
	}
	return (a);
}

// int	main(void)
// {

// 	return (0);
// }