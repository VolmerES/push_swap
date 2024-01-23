/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelorme <jdelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 18:30:48 by jdelorme          #+#    #+#             */
/*   Updated: 2024/01/23 14:20:23 by jdelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_lstclear_node(t_node **lst)
{
	t_node	*actnod;
	t_node	*nxtnod;

	if (!lst || !*lst)
		return ;
	actnod = *lst;
	while (actnod)
	{
		nxtnod = actnod->next;
		free(actnod);
		actnod = nxtnod;
	}
	*lst = NULL;
}

void	ft_free_matrix(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	ft_add_node(t_node **a, int nbr)
{
	t_node	*temp_node;

	temp_node = ft_lstnew_node(nbr);
	ft_lstadd_back_node(a, temp_node);
}

int	ft_stack_init(t_node **a, char **split)
{
	int		i;
	long	nbr;

	i = 0;
	while (split[i])
	{
		ft_syntax(split[i]);
		nbr = ft_atol(split[i]);
		// ! COMPROBAR
		if (nbr < INT_MIN || nbr > INT_MAX)
		{
			write(2, "Error\n", 6);
			return (1);
		}
		ft_repetition(*a, (int)nbr);
		ft_add_node(a, nbr);
		++i;
	}
	ft_free_matrix(split);
	return (0);
}
