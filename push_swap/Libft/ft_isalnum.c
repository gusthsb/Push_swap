/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustde-s <gustde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 19:14:49 by gustde-s          #+#    #+#             */
/*   Updated: 2026/05/19 19:29:56 by gustde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int a)
{
	if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z')
		|| (a >= '0' && a <= '9'))
		return (1);
	else
		return (0);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char	pokemon;
// 	char	digimon;

// 	pokemon = 'b';
// 	digimon = '=';
// 	if (ft_isalnum(pokemon) == 1)
// 		printf("é um alfanumerico\n");
// 	if (ft_isalnum(digimon) == 0)
// 		printf("não é um alfanumerico\n");
// 	return (0);
// }