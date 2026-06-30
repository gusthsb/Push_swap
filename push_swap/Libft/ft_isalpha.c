/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustde-s <gustde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 18:40:27 by gustde-s          #+#    #+#             */
/*   Updated: 2026/05/19 18:46:52 by gustde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int a)
{
	if ((a >= 'A' && a <= 'Z') || (a >= 'a' && a <= 'z'))
		return (1);
	else
		return (0);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char letter1;
// 	char thing;

// 	letter1 = 'a';
// 	thing = '-';
// 	if (ft_isalpha(letter1) == 1)
// 		printf("é um alfabetico\n");
// 	if (ft_isalpha(thing) == 0)
// 		printf("não é um alfabetico\n");
// 	return (0);
// }