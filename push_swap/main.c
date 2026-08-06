/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustde-s <gustde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 17:28:37 by mamatos-          #+#    #+#             */
/*   Updated: 2026/08/03 20:09:19 by gustde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	args_validation(int argc, char **argv, long **array, int *size)
{
	int	i;

	i = 0;
	while (i < argc - 1)
	{
		if (!checking_error(argv[i + 1]))
			return (0);
		i++;
	}
	*size = argc - 1;
	*array = trans_a_to_long((const char **)&argv[i]);
	if (!*array)
		return (0);
	if (is_array_duplicate(*array, *size))
	{
		free(*array);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	long	*array;
	int		size;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	if (!args_validation(argc, argv, &array, &size))
		return (ft_error());
}