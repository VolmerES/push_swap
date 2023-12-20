/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelorme <jdelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 18:26:03 by jdelorme          #+#    #+#             */
/*   Updated: 2023/12/20 18:29:02 by jdelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_swap_swap(t_node **a, t_node **b)
{
    ft_swap(a);
    // ft_swap(b);
    write(1, "ss\n", 3);
}
void   ft_swap_a(t_node **a)
{
    ft_swap(a);
    write(1, "sa\n", 3);
}
void   ft_swap_b(t_node **b)
{
    ft_swap(b);
    write(1, "sb\n", 3);
}