/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelorme <jdelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:58:21 by jdelorme          #+#    #+#             */
/*   Updated: 2023/12/18 19:02:08 by jdelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <limits.h>

typedef struct s_node
{
	int 			*value;
	struct s_node	*next;
    struct s_node	*prev;
}					t_node;

int    ft_syntax(char *split)
{
    //gestionar los negativos
    int j;
    
    j = 0;
    printf("-->%c \n", split[0]);
    while (split[j] != '\0')
    {
        if (split[j] < '0' || split[j] > '9')
        {
            printf("-->%c \n", split[j]);
            printf("ERROR_SYNTAX: Not numerical arguments");
            return(1);
        }
        j++;
    }
    return (0);
}
int   ft_stack_init(t_node *a, char **split)
{
    int     i;
    long     nbr;

    i = 0;
    while (split[i])
    {
        ft_syntax(split[i]);
        //ft_atol
        nbr = ft_atoi(split[i]);
        if (nbr < INT_MIN || nbr > INT_MAX)
        {
            printf("ERROR_INT: Number too long");
            return (1);
        }
        //control de repeteicion
        //ft_add_node()
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
    
    if (argc > 2)
        return (1);
    a = NULL;
    b = NULL;
    split = ft_join_args(argv);
    ft_stack_init(a, split);
    
}