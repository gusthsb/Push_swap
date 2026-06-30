/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustde-s <gustde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 18:25:23 by gustde-s          #+#    #+#             */
/*   Updated: 2026/05/25 18:37:35 by gustde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
	{
		return (c - 32);
	}
	else
		return (c);
}

// int	main(void)
// {
// 	char	letter = 'a';

// 	printf("Antes: %c\n", letter);
// 	letter = ft_toupper(letter);
// 	ft_toupper(letter);
// 	printf("Depois: %c\n", letter);
// 	return (0);
// }