/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustde-s <gustde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 19:26:59 by gustde-s          #+#    #+#             */
/*   Updated: 2026/06/25 16:12:32 by gustde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_hex_pointer(unsigned long n)
{
	char	*base;
	char	digit;
	int		count;

	base = "0123456789abcdef";
	count = 0;
	if (n >= 16)
		count += print_hex_pointer(n / 16);
	digit = base[n % 16];
	write(1, &digit, 1);
	return (count + 1);
}

int	ft_print_pointer(void *ptr)
{
	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	return (print_hex_pointer((unsigned long)ptr) + 2);
}
