/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelorme <jdelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 18:20:57 by jdelorme          #+#    #+#             */
/*   Updated: 2024/01/08 16:02:50 by jdelorme         ###   ########.fr       */
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

int		ft_lstsize_node(t_node *lst);
void	ft_lstadd_back_node(t_node **lst, t_node *new);
void    ft_add_node(t_node **a, int nbr);
t_node	*ft_lstnew_node(int nbr);
t_node	*ft_lstlast_node(t_node **stack);

void    ft_swap(t_node **stack);
void    ft_reverse_rotate(t_node **stack);
void    ft_rotate(t_node **stack);
void    ft_push(t_node **a, t_node **b);

int		ft_check_ordered(t_node **a);
int		ft_syntax(char *split);
int		ft_repetition(t_node *a, int nbr);

int		ft_stack_init(t_node **a, char **split);
char	**ft_join_args(char **argv);

void    ft_swap_swap(t_node **a, t_node **b);
void	ft_swap_a(t_node **a);
void	ft_swap_b(t_node **b);
void    ft_rotate_a(t_node **a);
void    ft_rotate_b(t_node **b);
void    ft_rotate_ab(t_node **a, t_node **b);
void    ft_reverse_rotate_a(t_node **a);
void    ft_reverse_rotate_b(t_node **b);
void    ft_reverse_rotate_ab(t_node **a, t_node **b);
void    ft_push_b(t_node **b, t_node **a);
void    ft_push_a(t_node **a, t_node **b);

void   ft_three_stack(t_node **a);
void   ft_four_stack(t_node **a, t_node **b);
int		ft_find_min(t_node *node);
void   ft_five_stack(t_node **a, t_node **b);