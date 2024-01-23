/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelorme <jdelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:25:40 by jdelorme          #+#    #+#             */
/*   Updated: 2024/01/23 14:09:43 by jdelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_reverse_rotate(t_node **stack)
{
	t_node	*temp1;
	t_node	*temp2;

	temp2 = *stack;
	while (temp2->next->next)
		temp2 = temp2->next;
	temp1 = temp2->next;
	temp1->next = *stack;
	temp2->next = NULL;
	*stack = temp1;
}

void	ft_reverse_rotate_a(t_node **a)
{
	ft_reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	ft_reverse_rotate_b(t_node **b)
{
	ft_reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	ft_reverse_rotate_ab(t_node **a, t_node **b)
{
	ft_reverse_rotate_a(a);
	ft_reverse_rotate_b(b);
	write(1, "rrr\n", 4);
}
