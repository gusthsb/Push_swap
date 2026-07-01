/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustde-s <gustde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 17:06:42 by gustde-s          #+#    #+#             */
/*   Updated: 2026/06/30 17:10:24 by gustde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "ftprintf/ft_printf.h"
/* prototipações no .h e include da library do malloc*/
typedef struct s_list /* se utilizar junto com a libft, tem que mudar o nome pq é a msm struct, fiquei com preguiça e apaguei a lib então*/
{
	int				*content; /* mudando tipo void * para int * (so vamos trabalhar com inteiros, então void é desnecessário)*/
	int				index; /* adicionando int index para otimizar/facilitar comparação dos numeros */
	struct s_list	*next;
}					t_list;

void	swap_a(t_list **lst);
void	swap_b(t_list **lst);
void	swap_both(t_list **lst_a, t_list **lst_b);
void	rotate_a(t_list **lst_a);
void	rotate_b(t_list **lst_b);
void	rr(t_list **lst_a, t_list **lst_b);
void	reverse_rotate_a(t_list **lst_a);
void	reverse_rotate_b(t_list **lst_b);
void	rrr(t_list **lst_a, t_list **lst_b);
void	push_a(t_list **lst_b, t_list **lst_a);
void	push_b(t_list **lst_a, t_list **lst_b);

#endif