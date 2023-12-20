/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelorme <jdelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 18:30:48 by jdelorme          #+#    #+#             */
/*   Updated: 2023/12/20 18:31:00 by jdelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_add_node(t_node **a, int nbr)
{
    t_node  *temp_node;
    
    temp_node = ft_lstnew_node(nbr);
    ft_lstadd_back_node(a, temp_node);
}

int   ft_stack_init(t_node **a, char **split)
{
    int     i;
    long     nbr;
    t_node  *temp_node;

    i = 0;
    while (split[i])
    {
        // Comprobacion de que sean argumentos numericos
        ft_syntax(split[i]);
        //ft_atol, sino da error y no detecta int max y int min
        nbr = ft_atoi(split[i]);
        if (nbr < INT_MIN || nbr > INT_MAX)
        {
            printf("ERROR_INT: Number too long");
            return (1);
        }
        // Control de numeros repetidos
        ft_repetition(*a, (int)nbr);
        ft_add_node(a, nbr);
        ++i;
    }
  
    return (0);
}