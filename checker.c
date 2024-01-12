/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelorme <jdelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 18:30:14 by jdelorme          #+#    #+#             */
/*   Updated: 2024/01/11 13:01:17 by jdelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    ft_check_ordered(t_node **a)
{
    t_node  *temp;

    temp = *a;
    while (temp && temp->next)
    {
        if (temp->value > temp->next->value)
        {
            return (1);
        }
        temp = temp->next;
    }
    printf("Esta ordenado\n");
    return (0); 
}
int    ft_syntax(char *split)
{
    int j;
    
    j = 0;
    if (split[j] == '-' || split[j] == '+')
        j++;
    while (split[j] != '\0')
    {
        if (split[j] < '0' || split[j] > '9')
        {
            printf("ERROR_SYNTAX: Not numerical arguments");
            return(1);
        }
        j++;
    }
    return (0);
}
int  ft_repetition(t_node *a, int nbr)
{
    t_node  *temp;
    
    temp = a;
    while (temp)
    {
        if (temp->value == nbr)
        {
            printf("REPETITION_ERROR\n");
            return (1);
        }
        temp = temp->next;
    }
    return (0);
}