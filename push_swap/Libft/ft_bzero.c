/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustde-s <gustde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 15:31:43 by gustde-s          #+#    #+#             */
/*   Updated: 2026/06/10 19:55:22 by gustde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*temp;

	temp = (unsigned char *)s;
	while (n > 0)
	{
		*temp = 0;
		temp++;
		n--;
	}
}
// int main(void)
// {
//     char    str[5];
//     int     i;

//     str[0] = 'H';
//     str[1] = 'e';
//     str[2] = 'l';
//     str[3] = 'l';
//     str[4] = 'o';

//     printf("Antes: %s\n", str);
//     ft_bzero(str, 5);

//     i = 0;
//     while (i < 5)
//     {
//         printf("str[%d] = %d\n", i, str[i]);
//         i++;
//     }
//     return (0);
// }