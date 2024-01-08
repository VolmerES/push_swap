/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelorme <jdelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:26:04 by jdelorme          #+#    #+#             */
/*   Updated: 2024/01/08 16:01:21 by jdelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//estionar si los nodos estan vacios y que no escriba
void    ft_push(t_node **a, t_node **b)
{
    t_node  *temp1;
    t_node  *temp2;
    
    temp1 = *a;
    temp2 = *b;
    *a = (*a)->next;
    temp1->next = temp2;
    *b = temp1;   
}

void    ft_push_a(t_node **a, t_node **b)
{
    ft_push(a, b);
    write(1, "pa\n", 3);
}
void    ft_push_b(t_node **b, t_node **a)
{
    ft_push(b, a);
    write(1, "pb\n", 3);
}
