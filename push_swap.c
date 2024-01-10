/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelorme <jdelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:58:21 by jdelorme          #+#    #+#             */
/*   Updated: 2024/01/10 20:35:18 by jdelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//Arreglar esta funcion, esta comprobando la cantidad de bits que tiene un numero,
// pero no la cantidad de bits que tendre que comprobar despues en mi programa
// principal push swap.
int ft_calculate_bits(int nb)
{
    int count;

    printf("MAX--->%d\n", nb);
    count = 0;
    while (nb > 0)
    {
        count += nb & 1;
        nb >>= 1;
    }
    printf("MAX--->%d\n", count);
    return (count);
}
int ft_find_max_bits(t_node **a)
{
    int     i;
    int     value;
    t_node  *head;
    
    i = 0;
    value = 0;
    head = (*a);
    while ((*a))
    {
        if ((*a)->index > i)
            i = (*a)->index;
        (*a) = (*a)->next;
    }
    (*a) = head;
    while ((*a))
    {
        if ((*a)->index == i)
        {
            value = (*a)->value;
            return (value);
        }
        (*a) = (*a)->next;
    }
    (*a) = head;
    return (value);
}
int ft_set_index(t_node **a)
{
    int i;
    int com;
    t_node *head;
    t_node *runner;
    
    head = (*a);
    while (head)
    {
        i = 0;
        com = head->value;
        runner = *a;
        while (runner)
        {
            if (com > runner->value)
                i++;
            runner = runner->next;
        }
        head->index = i;
        head = head->next;
    }
    return(i);
}

void    ft_push_swap(t_node **a, t_node **b)
{
    int max_bits;
    int stack_size;
    int i;
    t_node  *head;

    ft_set_index(a);
    max_bits = ft_find_max_bits(a);
    max_bits = ft_calculate_bits(max_bits);
    stack_size = (ft_lstsize_node(*a));
    i = (max_bits - 1);
    printf("------------->%d\n", i);
    while (i >= 0)
    {
      
        head = *a;
        while (head)
        {
            if (((head->index >> i) & 1) == 1)
                ft_rotate_a(a);
            if (((head->index >> i) & 1) == 0)
                ft_push_a(a, b);
            head = head->next;
        }
        i--;
    }
}
//  Llevarme todos los numeros binarios terminados en 0 a stack de b (PUSH A);
//  Volver a traerlos en al stack de A;
//  Repetir el proceso en bit por bit

char	**ft_join_args(char **argv)
{
	char	*tmp;
	char	*str;
	char	**split;
	int		i;

	i = 1;
	tmp = ft_strdup(" ");
	while (argv[i])
	{
		str = ft_strjoin(tmp, argv[i]);
		free(tmp);
		tmp = ft_strjoin(str, " \0");
		free(str);
		i++;
	}
	split = ft_split(tmp, ' ');
	free(tmp);
	return (split);
}

int main(int argc, char **argv)
{
    t_node  *a;
    t_node  *b;
    char    **split;
    
    if (argc < 2)
        return (1);
    a = NULL;
    b = NULL;
    split = ft_join_args(argv);
    int i = 0;
    // ! Control 1
    // printf("--------------------\n");
    // while (split[i] != NULL)
    // {
    //     printf("Matrix value--> %s\n", split[i]);
    //     i++;
    // }
    // printf("--------------------\n");
    ft_stack_init(&a, split);
    // ! FIN DE CONTROL
    if (ft_check_ordered(&a))
    {
        if (ft_lstsize_node(a) == 2)
            ft_swap_a(&a);
        if (ft_lstsize_node(a) == 3)
            ft_three_stack(&a);
        if (ft_lstsize_node(a) == 4)
            ft_four_stack(&a, &b);
        if (ft_lstsize_node(a) == 5)
            ft_five_stack(&a, &b);
        else
            ft_push_swap(&a, &b);
    }
     while(a)
    {
        printf("a--> %d\n", a->value);
        //  printf("ain--> %d\n", a->index);
        a = a->next;
    }
    printf("--------------------\n");
      while(b)
    {
        printf("b--> %d\n", b->value);
        b = b->next;
    }
}
