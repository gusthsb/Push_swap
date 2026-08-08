/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustde-s <gustde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 17:28:37 by mamatos-          #+#    #+#             */
/*   Updated: 2026/08/07 17:29:43 by gustde-s         ###   ########.fr       */
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
	*array = trans_a_to_long((const char **)&argv[1]);
	if (!*array)
		return (0);
	if (is_array_duplicate(*array, *size))
	{
		free(*array);
		return (0);
	}
	return (1);
}

static int	op_reading(int argc, char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (ft_strcmp(argv[i], "--adaptive") || ft_strcmp(argv[i], "--simple"))
		{
			sort_simple(t_list **stack_a, t_list **stack_b);
			return ;
		}
		else if (ft_strcmp(argv[i], "--complex"))
			NULL;
		else if (ft_strcmp(argv[i], "--medium"))
			NULL;
		i++;
	}
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
	free(array);
	trans_arr_to_lst(&stack_a, argv);
	set_stack_indexes(stack_a);
	if (size <= 1)
	{
		ft_lstclear(&stack_a);
		return (0);
	}
	(void)stack_b;
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	return (0);
}
