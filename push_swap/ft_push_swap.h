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
}			t_list;

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
void	push_a(t_list **lst_b, t_list **lst_a);
void	push_b(t_list **lst_a, t_list **lst_b);

// disorder functions
double main_disorder(t_list *lst);

// index functions
void	set_stack_indexes(t_list *lst_a);

// utils functions
t_list	*ft_lstnew(int content);
int		lst_size(t_list *lst);
int		ft_isdigit(int c);
long	ft_atol(const char *str);
void	ft_lstadd_back(t_list **lst, t_list *new);

#endif
