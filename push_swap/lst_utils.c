/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustde-s <gustde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 16:50:41 by mamatos-          #+#    #+#             */
/*   Updated: 2026/08/13 17:20:37 by gustde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int lst_size(t_list *lst)
{
    int     size;
    t_list  *start;

    if (!lst)
        return (0);
    size = 1;
    start = lst;
    lst = lst -> next;
    while (lst != start)
    {
        size++;
        lst = lst -> next;
    }
    return (size);
}

void    ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list  *temp;

    if (!lst || !new)
        return ;
    if (*lst == NULL)
    {
        *lst = new;
        new -> next = new;
        new -> prev = new;
        return ;
    }
    temp = (*lst)-> prev;
    temp -> next = new;
    new -> prev = temp;
    new -> next = *lst;
    (*lst)-> prev = new;
}

t_list  *ft_lstnew(int content)
{
    t_list  *new_node;

    new_node = malloc(sizeof(t_list));
    if (!new_node)
        return (NULL);
    new_node->content = content;
    new_node -> index = 0;
    new_node->next = new_node;
    new_node -> prev = new_node;
    return (new_node);
}

void    ft_lstclear(t_list **lst)
{
    t_list  *current;
    t_list  *next;

    if (!lst || !*lst)
        return ;
    current = (*lst)-> next;
    while (current != *lst)
    {
        next = current -> next;
        free(current);
        current = next;
    }
    free(*lst);
    *lst = NULL;
}

int get_max_index_pos(t_list **lst)
{
    int     max_pos;
    int     current_pos;
    int     max_index;
    t_list  *lst_temp;

    if (!lst || !*lst)
        return (0);
    max_pos = 0;
    current_pos = 1;
    max_index = (*lst)->index;
    lst_temp = (*lst)->next;
    while (lst_temp != *lst)
    {
        if(lst_temp->index > max_index)
        {
            max_index = lst_temp->index;
            max_pos = current_pos;
        }
        lst_temp = lst_temp->next;
        current_pos++;
    }
    return (max_pos);
}
