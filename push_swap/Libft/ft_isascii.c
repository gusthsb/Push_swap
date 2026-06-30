/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustde-s <gustde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 19:39:50 by gustde-s          #+#    #+#             */
/*   Updated: 2026/05/21 15:41:52 by gustde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int a)
{
	if (a >= 0 && a <= 127)
		return (1);
	else
		return (0);
}

// #include <stdio.h>
// int main(void)
// {
//     printf("Testando 'A' (dentro): %d\n", ft_isascii('A'));
// 	printf("Testando 150 (fora): %d\n", ft_isascii(150));

//     return (0);
// }