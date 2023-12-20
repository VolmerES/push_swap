/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelorme <jdelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 18:28:48 by jdelorme          #+#    #+#             */
/*   Updated: 2023/12/20 18:45:22 by jdelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize_node(t_node *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
void	ft_lstadd_back_node(t_node **lst, t_node *new)
{
	t_node	*actual;

	if (!*lst)
		*lst = new;
	else
	{
		actual = *lst;
		while (actual->next)
			actual = actual->next;
		actual->next = new;
    //     // ! Control 3
    //     printf("Next memdir: %p \n", actual->next);
    //     printf("--------------------\n");
	}
}
t_node	*ft_lstnew_node(int nbr)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = nbr;
	node->next = NULL;
    // // ! Control 2
    // printf("Node value--> %d\n", node->value);
    // printf("--------------------\n");
	return (node);
}
t_node	*ft_lstlast(t_node **stack);
{
	t_node	*ult;

	ult = stack;
	if (!lst)
		return (NULL);
	while (ult->next)
	{
		ult = ult->next;
	}
	return (ult);
}