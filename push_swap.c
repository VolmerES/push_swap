/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelorme <jdelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:58:21 by jdelorme          #+#    #+#             */
/*   Updated: 2023/12/19 18:48:48 by jdelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <limits.h>

typedef struct s_node
{
	int 			value;
	struct s_node	*next;
    struct s_node	*prev;
}					t_node;

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
        // ! Control 3
        printf("Next memdir: %p \n", actual->next);
        printf("--------------------\n");
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
    int i = 0;
    // ! Control 2
    printf("Node value--> %d\n", node->value);
    printf("--------------------\n");
	return (node);
}
int    ft_syntax(char *split)
{
    //gestionar los negativos
    int j;
    
    j = 0;
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
            printf("REPETITION_ERROR");
            return (1);
        }
        a = a->next;
    }
    return (0);
}

// void   *ft_add_node(t_node **a, int nbr)
// {
//     t_node  *temp_node;
    
//     temp_node = ft_lstnew_node(nbr);
//     ft_lstadd_back_node(a, temp_node);
// }


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
        temp_node = ft_lstnew_node(nbr);
        ft_lstadd_back_node(a, temp_node);
        ++i;
    }
  
    return (0);
}
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
    printf("--------------------\n");
    while (split[i] != NULL)
    {
        printf("Matrix value--> %s\n", split[i]);
        i++;
    }
    printf("--------------------\n");
    ft_stack_init(&a, split);
    
}