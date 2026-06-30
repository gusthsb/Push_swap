/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustde-s <gustde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 16:24:51 by gustde-s          #+#    #+#             */
/*   Updated: 2026/05/28 15:37:36 by gustde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	signal;
	int	res;

	i = 0;
	signal = 1;
	res = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signal *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * signal);
}	

// int main(void)
// {
//     printf("%d\n", ft_atoi("4"));
//     printf("%d\n", ft_atoi("   -4"));
//     printf("%d\n", ft_atoi("+4abc"));
//     printf("%d\n", ft_atoi("---4"));
//     printf("%d\n", ft_atoi("   4  "));
//     printf("%d\n", ft_atoi("abc"));
//     return (0);
// }