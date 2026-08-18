/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustde-s <gustde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 17:45:20 by gustde-s          #+#    #+#             */
/*   Updated: 2026/08/18 19:19:33 by gustde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	print_operations(char *op)
{
	if (ft_strcmp(op, "pa") == 0)
		write(1, "pa\n", 3);
	else if (ft_strcmp(op, "pb") == 0)
		write(1, "pb\n", 3);
	else if (ft_strcmp(op, "ra") == 0)
		write(1, "ra\n", 3);
	else if (ft_strcmp(op, "rb") == 0)
		write(1, "rb\n", 3);
	else if (ft_strcmp(op, "sa") == 0)
		write(1, "sa\n", 3);
	else if (ft_strcmp(op, "sb") == 0)
		write(1, "sb\n", 3);
	else if (ft_strcmp(op, "rr") == 0)
		write(1, "rr\n", 3);
	else if (ft_strcmp(op, "rrb") == 0)
		write(1, "rrb\n", 4);
	else if (ft_strcmp(op, "rra") == 0)
		write(1, "rra\n", 4);
	else if (ft_strcmp(op, "rrr") == 0)
		write(1, "rrr\n", 4);
}
