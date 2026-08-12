/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustde-s <gustde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 17:28:37 by mamatos-          #+#    #+#             */
/*   Updated: 2026/08/11 21:27:20 by gustde-s         ###   ########.fr       */
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

static void	dispatch_sort(t_config *config, t_list **stack_a,
	t_list **stack_b, t_count *op)
{
	if (ft_strcmp(config -> strategy, "simple") == 0)
		sort_simple(stack_a, stack_b, op);
	else
	{
		sort_simple(stack_a, stack_b, op);
	}
	// else if (ft_strcmp(config->strategy, "medium") == 0)
	// 	sort_medium(stack_a, stack_b, op);
	// else if (ft_strcmp(config->strategy, "complex") == 0)
	// 	sort_complex(stack_a, stack_b, op);
	// else if (ft_strcmp(config->strategy, "adaptive") == 0)
	// 	return ;
}

int	main(int argc, char **argv)
{
	t_list		*stack_a;
	t_list		*stack_b;
	t_config	config;
	char		**nums;
	long		*array;
	int			size;
	int			num_count;
	t_count	op;

	stack_a = NULL;
	stack_b = NULL;
	init_op(&op);
	if (argc < 2)
		return (0);
	parse_flags(argc, argv, &config);
	num_count = build_numeric_args(argc, argv, &nums);
	if (num_count < 0)
		return (ft_error());
	if (num_count == 0)
	{
		free(nums);
		return (0);
	}
	if (!args_validation(num_count + 1, nums, &array, &size))
	{
		free(nums);
		return (ft_error());
	}
	free(array);
	trans_arr_to_lst(&stack_a, nums);
	free(nums);
	set_stack_indexes(stack_a);
	if (size > 1 && !is_sorted(stack_a))
	{
		if (config.bench_mode)
		{
			print_disorder(main_disorder(stack_a));
			dispatch_sort(&config, &stack_a, &stack_b, &op);
			print_strategy(&config);
			print_total_ops(&op);
		}
		else
			dispatch_sort(&config, &stack_a, &stack_b, &op);	
	}
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	return (0);
}
