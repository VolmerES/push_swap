/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelorme <jdelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:58:21 by jdelorme          #+#    #+#             */
/*   Updated: 2023/12/12 18:05:38 by jdelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdbool.h>

typedef struct s_node
{
	int 			*value;
	struct s_node	*next;
    struct s_node	*prev;
}					t_node;

int main(int argc, char **argv)
{
    t_node  *a;
    t_node  *b;

    if (argc > 2)
        return (1);
    
}