/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustde-s <gustde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 18:50:59 by gustde-s          #+#    #+#             */
/*   Updated: 2026/05/21 15:41:30 by gustde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int a)
{
	if (a >= '0' && a <= '9')
		return (1);
	else
		return (0);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char	digimon;
// 	char	pokemon;

// 	digimon = '0';
// 	pokemon = 'p';
// 	if (ft_isdigit(digimon) == 1)
// 		printf("É um digito\n");
// 	if (ft_isdigit(pokemon) == 0)
// 		printf("Não é um digito\n");
// 	return (0);
// }