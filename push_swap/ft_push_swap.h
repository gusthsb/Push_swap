/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustde-s <gustde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 17:06:42 by gustde-s          #+#    #+#             */
/*   Updated: 2026/08/03 19:59:57 by gustde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "ftprintf/ft_printf.h"

typedef struct s_config
{
	int		bench_mode;
	char	*strategy;
}			t_config;

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
	struct s_list	*prev;
	
}					t_list;

# define INT_MAX 2147483647
# define INT_MIN -2147483648

void	swap_a(t_list **lst_a);
void	swap_b(t_list **lst_b);
void	swap_both(t_list **lst_a, t_list **lst_b);
void	rotate_a(t_list **lst_a);
void	rotate_b(t_list **lst_b);
void	rr(t_list **lst_a, t_list **lst_b);
void	reverse_rotate_a(t_list **lst_a);
void	reverse_rotate_b(t_list **lst_b);
void	rrr(t_list **lst_a, t_list **lst_b);
void	push_a(t_list **dst_a, t_list **src_b);
void	push_b(t_list **dst_b, t_list **src_a);

// disorder functions
double main_disorder(t_list *lst);

// index functions
void	set_stack_indexes(t_list *lst_a);

// utils functions
t_list	*ft_lstnew(int content);
int		lst_size(t_list *lst);
int		is_sorted(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst);
int		ft_strcmp(const char *s1, const char *s2);

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
void	min_to_b(t_list **stack_a, t_list **stack_b);
void	rotate_to_top(t_list **stack_a, int pos, int size);
int		min_position(t_list *lst);
void	three_sorted(t_list **lst);
void	two_sorted(t_list **lst);
void	sort_simple(t_list **stack_a, t_list **stack_b);

#endif
