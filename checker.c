/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelorme <jdelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 18:30:14 by jdelorme          #+#    #+#             */
/*   Updated: 2024/01/22 17:28:37 by jdelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_ordered(t_node **a)
{
	t_node	*temp;

	temp = *a;
	while (temp && temp->next)
	{
		if (temp->value > temp->next->value)
		{
			return (1);
		}
		temp = temp->next;
	}
	return (0);
}

int	ft_syntax(char *split)
{
	int	j;

	j = 0;
	if (((split[j] == '-' || split[j] == '+')) && (split[j + 1] == '\0'))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (split[j] == '-' || split[j] == '+')
		j++;
	while (split[j] != '\0')
	{
		if (split[j] < '0' || split[j] > '9')
		{
			write(2, "Error\n", 6);
			return (1);
		}
		j++;
	}
	return (0);
}

int	ft_repetition(t_node *a, int nbr)
{
	t_node	*temp;

	temp = a;
	while (temp)
	{
		if (temp->value == nbr)
		{
			write(2, "Error\n", 6);
			return (1);
		}
		temp = temp->next;
	}
	return (0);
}
