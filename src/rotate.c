/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelorme <jdelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:24:41 by jdelorme          #+#    #+#             */
/*   Updated: 2024/01/23 16:10:50 by jdelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_rotate(t_node **stack)
{
	t_node	*temp;
	t_node	*temp2;

	if ((!(*stack)) || (!(*stack)->next))
		return ;
	temp2 = (*stack)->next;
	temp = ft_lstlast_node(stack);
	temp->next = *stack;
	(*stack)->next = NULL;
	*stack = temp2;
}

void	ft_rotate_a(t_node **a)
{
	ft_rotate(a);
	write(1, "ra\n", 3);
}

void	ft_rotate_b(t_node **b)
{
	ft_rotate(b);
	write(1, "rb\n", 3);
}

void	ft_rotate_ab(t_node **a, t_node **b)
{
	ft_rotate_a(a);
	ft_rotate_b(b);
	write(1, "rr\n", 3);
}
