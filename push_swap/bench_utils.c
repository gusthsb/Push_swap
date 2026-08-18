/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustde-s <gustde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 19:24:11 by gustde-s          #+#    #+#             */
/*   Updated: 2026/08/18 19:24:12 by gustde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	put_str_fd(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	write(2, s, i);
}

void	put_nbr_fd(int n)
{
	char	c;

	if (n < 0)
	{
		write(2, "-", 1);
		n = -n;
	}
	if (n >= 10)
		put_nbr_fd(n / 10);
	c = (n % 10) + '0';
	write(2, &c, 1);
}

void	print_double_2dec(double n)
{
	int	whole;
	int	frac;

	whole = (int)n;
	frac = (int)((n - whole) * 100 + 0.5);
	if (frac >= 100)
	{
		frac = 0;
		whole++;
	}
	put_nbr_fd(whole);
	write(2, ".", 1);
	if (frac < 10)
		write(2, "0", 1);
	put_nbr_fd(frac);
}
