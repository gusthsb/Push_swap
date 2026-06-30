/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustde-s <gustde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 19:39:36 by gustde-s          #+#    #+#             */
/*   Updated: 2026/05/26 16:41:18 by gustde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (0);
	while (str1[i] != '\0' && str1[i] == str2[i] && i < size - 1)
	{
		i++;
	}
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}

// int main(void)
// {
//     char s1[40] = "Ola, mundo";
//     char s2[40] = "Ola, m";
//     size_t	n;

// 	n = 7;
//     printf("--- Teste 1 ---\n");
//     printf("ft_strncmp: %d\n", ft_strncmp(s1, s2, n));
//     printf("\n--- Teste 2 (n = 0) ---\n");
//     printf("ft_strncmp: %d\n", ft_strncmp(s1, s2, 0));
//     printf("\n--- Teste 3 (Strings iguais) ---\n");
//     printf("ft_strncmp: %d\n", ft_strncmp("Igual", "Igual", 10));
//     return (0);
// }