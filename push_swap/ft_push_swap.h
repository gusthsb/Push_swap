/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustde-s <gustde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 17:06:42 by gustde-s          #+#    #+#             */
/*   Updated: 2026/08/18 19:38:32 by gustde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_config
{
	int		bench_mode;
	char	*strategy;
	double	initial_disorder;
}			t_config;

typedef struct s_op
{
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	sa;
	int	sb;
	int	ss;
	int	rra;
	int	rrb;
	int	rrr;
	int	count;
}				t_count;

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

typedef struct s_chunk
{
	int	chunk_end;
	int	mid;
	int	size;
}	t_chunk;

# define INT_MAX 2147483647
# define INT_MIN -2147483648

void	swap_a(t_list **lst_a, t_count *op);
void	swap_b(t_list **lst_b, t_count *op);
void	swap_both(t_list **lst_a, t_list **lst_b, t_count *op);
void	rotate_a(t_list **lst_a, t_count *op);
void	rotate_b(t_list **lst_b, t_count *op);
void	rr(t_list **lst_a, t_list **lst_b, t_count *op);
void	reverse_rotate_a(t_list **lst_a, t_count *op);
void	reverse_rotate_b(t_list **lst_b, t_count *op);
void	rrr(t_list **lst_a, t_list **lst_b, t_count *op);
void	push_a(t_list **dst_a, t_list **src_b, t_count *op);
void	push_b(t_list **dst_b, t_list **src_a, t_count *op);

// disorder functions
double	main_disorder(t_list *lst);

// index functions
void	set_stack_indexes(t_list *lst_a);

// utils functions
t_list	*ft_lstnew(int content);
int		lst_size(t_list *lst);
int		is_sorted(t_list *lst);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst);
void	init_op(t_count *op);
int		get_max_index_pos(t_list **lst);
void	cleanup(t_list **stack_a, t_list **stack_b);
int		should_sort(t_list *stack_a);
void	handle_output(t_config *config, t_count *op);

// verifications functions
int		is_array_duplicate(long	*arr, int size);
int		ft_error(void);
int		ft_isdigit(int c);
int		is_inter(char *str);
long	ft_atol(const char *str);
int		checking_error(char *str);

// trans functions
long	*trans_a_to_long(const char **str);
void	trans_arr_to_lst(t_list **lst, char **arr);

// sort functions // sort utils
int		min_position(t_list *lst);
void	min_to_b(t_list **stack_a, t_list **stack_b, t_count *op);
void	rotate_to_top(t_list **stack_a, int pos, int size, t_count *op);
void	two_sorted(t_list **lst, t_count *op);
void	three_sorted(t_list **lst, t_count *op);
void	sort_simple(t_list **stack_a, t_list **stack_b, t_count *op);
void	sort_medium(t_list **stack_a, t_list **stack_b, t_count *op);
void	sort_complex(t_list **stack_a, t_list **stack_b, t_count *op);
void	sort_adaptive(t_list **stack_a, t_list **stack_b, t_count *op);
int		ft_sqrt(int number);
void	push_chunk_element(t_list **a, t_list **b, t_chunk *chunk,
			t_count *op);
void	process_chunk(t_list **a, t_list **b, t_chunk *chunk,
			t_count *op);
void	chunks_b(t_list **a, t_list **b, int size, t_count *op);
void	bring_max_to_top(t_list **b, int max_pos, int b_size,
			t_count *op);

// flags functions
void	parse_flags(int argc, char **argv, t_config *config);
int		build_numeric_args(int argc, char **argv, char ***out);

// print functions
void	print_disorder(double disorder);
void	print_bench(t_list *a, t_config *config, t_count *op);
void	print_total_ops(t_count *op);
void	print_strategy(t_config *strategy);
void	put_nbr_fd(int n);
void	put_str_fd(char *s);
void	print_double_2dec(double n);
void	print_operations(char *op);

#endif
