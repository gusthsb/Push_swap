/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustde-s <gustde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 18:10:00 by gustde-s          #+#    #+#             */
/*   Updated: 2026/06/01 19:46:26 by gustde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_dig(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long	nb;
	int		len;
	char	*res;

	nb = n;
	len = count_dig(nb);
	res = (char *)malloc(len + 1);
	if (!res)
		return (NULL);
	res[len--] = '\0';
	if (nb == 0)
		res[0] = '0';
	if (nb < 0)
	{
		res[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		res[len--] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (res);
}

// int	main(void)
// {
// 	char *r1;
// 	char *r2;
// 	char *r3;
// 	r1 = ft_itoa(1234);
// 	r2 = ft_itoa(-1234);
// 	r3 = ft_itoa(0);
// 	printf("%s\n", r1);
// 	printf("%s\n", r2);
// 	printf("%s\n", r3);
// 	return (0);
// }