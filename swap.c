/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelorme <jdelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:23:28 by jdelorme          #+#    #+#             */
/*   Updated: 2024/01/12 12:19:49 by jdelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_node **stack)
{
	t_node	*temp;

	temp = (*stack)->next;
	(*stack)->next = temp->next;
	temp->next = *stack;
	*stack = temp;
}

void	ft_swap_swap(t_node **a, t_node **b)
{
	ft_swap(a);
	ft_swap(b);
	write(1, "ss\n", 3);
}

void	ft_swap_a(t_node **a)
{
	ft_swap(a);
	write(1, "sa\n", 3);
}

void	ft_swap_b(t_node **b)
{
	ft_swap(b);
	write(1, "sb\n", 3);
}
