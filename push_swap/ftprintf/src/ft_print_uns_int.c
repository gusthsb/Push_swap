/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uns_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustde-s <gustde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 19:27:06 by gustde-s          #+#    #+#             */
/*   Updated: 2026/06/16 20:10:40 by gustde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_uns_int(unsigned int n)
{
	int	count;
	int	digit;

	count = 0;
	if (n >= 10)
		count += ft_print_uns_int(n / 10);
	digit = (n % 10) + '0';
	write(1, &digit, 1);
	return (count + 1);
}
