/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelorme <jdelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:58:21 by jdelorme          #+#    #+#             */
/*   Updated: 2023/12/20 18:35:06 by jdelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void    ft_sort_two(t_node **a)
// {
//     t_node *temp;

//     temp = a->next;
//     a = a->next->
    
// }
// void    ft_little_stack(t_node **a)
// {
//     if (ft_lstsize_node == 2)
//         ft_sort_two(a);
    // if (ft_lstsize_node == 3)
    //     ft_little_sort();
    // if (ft_lstsize_node == 4)
    //     ft_little_sort();
    // if (ft_lstsize_node == 5)
    //     ft_little_sort();
//}

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
    //    ft_swap(&a);
        ft_swap_swap(&a, &b);
        // if (ft_lstsize_node < 5)
        //     ft_little_stack(&a);
        // else
        //     ft_push_swap;
    }
     while(a)
    {
        printf("--> %d\n", a->value);
        a = a->next;
    }
}