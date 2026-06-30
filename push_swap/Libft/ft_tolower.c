/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustde-s <gustde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 18:38:16 by gustde-s          #+#    #+#             */
/*   Updated: 2026/05/25 18:41:50 by gustde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	else
		return (c);
}
// int	main(void)
// {
// 	char	letter;

// 	letter = 'A';
// 	printf("Antes: %c\n", letter);
// 	letter = ft_tolower(letter);
// 	printf("Depois: %c\n", letter);
// 	return (0);
// }
