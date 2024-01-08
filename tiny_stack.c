/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelorme <jdelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:38:00 by jdelorme          #+#    #+#             */
/*   Updated: 2024/01/08 16:05:18 by jdelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_find_min(t_node *node)
{
    int i;
    int nb;
    t_node *head;

    i = 0;
    nb = INT_MAX;
    head = node;
    while (node)
    {
        if (nb > node->value)
        {
            nb = node->value;
        }
        node = node->next;
    }
    node = head;
    while (node)
    {
        if (nb == node->value)
        {
            printf("%d\n", i);
            return (i);
        }
        i++;
        node = node->next;
    }
    return (i);
}

 void   ft_three_stack(t_node **a)
 {
    if ((*a)->value > (*a)->next->value)
        ft_swap_a(a);
    if (!ft_check_ordered(a))
        return;
    if ((*a)->value < (*a)->next->value)
        ft_reverse_rotate_a(a);
    if ((*a)->value > (*a)->next->value)
        ft_swap_a(a);
 }

 void   ft_four_stack(t_node **a, t_node **b)
 {
    int i;
    
    i = ft_find_min(*a);
    while (i)
    {
        ft_rotate_a(a);
        i--;
    }
    ft_push_a(a, b);
    ft_three_stack(a);
    ft_push_b(b, a);
 }

 void   ft_five_stack(t_node **a, t_node **b)
 {
     int i;
    
    i = ft_find_min(*a);
    while (i)
    {
        ft_rotate_a(a);
        i--;
    }
    ft_push_a(a, b);
    ft_four_stack(a, b);
    ft_push_b(b, a);
 }