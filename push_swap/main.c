/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustde-s <gustde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 17:28:37 by mamatos-          #+#    #+#             */
/*   Updated: 2026/08/18 19:14:59 by gustde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int  validate_numeric_array(int argc, char **argv, long **array, int *size)
{
    int i;

    i = 0;
    while (i < argc - 1)
    {
        if (!checking_error(argv[i + 1]))
            return (0);
        i++;
    }
    *size = argc - 1;
    *array = trans_a_to_long((const char **)&argv[1]);
    if (!*array || is_array_duplicate(*array, *size))
    {
        if (*array)
            free(*array);
        return (0);
    }
    return (1);
}

static void build_stacks(char **nums, int num_count, t_list **stack_a)
{
    long    *array;
    int     size;

    if (!validate_numeric_array(num_count + 1, nums, &array, &size))
    {
        free(nums);
        ft_error();
        return ;
    }
    free(array);
    trans_arr_to_lst(stack_a, nums);
    free(nums);
    set_stack_indexes(*stack_a);
}

static int  init_env(int argc, char **argv, t_config *config, t_list **stack_a)
{
    char    **nums;
    int     num_count;

    parse_flags(argc, argv, config);
    num_count = build_numeric_args(argc, argv, &nums);
    if (num_count < 0)
    {
        ft_error();
        return (0);
    }
    if (num_count == 0)
    {
        free(nums);
        return (0);
    }
    build_stacks(nums, num_count, stack_a);
    if (!*stack_a)
        return (0);
    return (1);
}

static void execute_sort(t_config *config, t_list **a, t_list **b, t_count *op)
{
    if (ft_strcmp(config->strategy, "simple") == 0)
        sort_simple(a, b, op);
    else if (ft_strcmp(config->strategy, "medium") == 0)
        sort_medium(a, b, op);
    else if (ft_strcmp(config->strategy, "complex") == 0)
        sort_complex(a, b, op);
    else if (ft_strcmp(config->strategy, "adaptive") == 0)
        sort_adaptive(a, b, op);
}

int main(int argc, char **argv)
{
    t_list      *stack_a;
    t_list      *stack_b;
    t_config    config;
    t_count     op;

    if (argc < 2)
        return (0);
    stack_a = NULL;
    stack_b = NULL;
    init_op(&op);
    if (!init_env(argc, argv, &config, &stack_a))
        return (0);
    if (should_sort(stack_a))
	{
		config.initial_disorder = main_disorder(stack_a);
        execute_sort(&config, &stack_a, &stack_b, &op);
	}
	else
		config.initial_disorder = 0.0;
    handle_output(&config, &op);
    cleanup(&stack_a, &stack_b);
    return (0);
}
