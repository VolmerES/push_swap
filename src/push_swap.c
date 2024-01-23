/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelorme <jdelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:58:21 by jdelorme          #+#    #+#             */
/*   Updated: 2024/01/23 14:09:37 by jdelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_find_max_bits(t_node **a)
{
	int	i;
	int	lst;

	i = 0;
	lst = (ft_lstsize_node(*a));
	while ((lst >> i) != 0)
		i++;
	return (i);
}

int	ft_set_index(t_node **a)
{
	int		i;
	int		com;
	t_node	*head;
	t_node	*runner;

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
	return (i);
}

void	ft_push_swap(t_node **a, t_node **b)
{
	int	max_bits;
	int	stack_size;
	int	i;
	int	value;
	int	j;

	ft_set_index(a);
	max_bits = ft_find_max_bits(a);
	stack_size = (ft_lstsize_node(*a));
	i = -1;
	while (++i < max_bits)
	{
		j = -1;
		while (++j < stack_size)
		{
			value = (*a)->index;
			if (((value >> i) & 1) == 1)
				ft_rotate_a(a);
			if (((value >> i) & 1) == 0)
				ft_push_b(a, b);
		}
		while (ft_lstsize_node(*b) != 0)
			ft_push_a(b, a);
	}
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
	if (split[0] == NULL)
		write(2, "Error\n", 6);
	free(tmp);
	return (split);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	char	**split;
	int		i;

	if (argc < 2)
		return (1);
	a = NULL;
	b = NULL;
	split = ft_join_args(argv);
	i = 0;
	ft_stack_init(&a, split);
	if (ft_check_ordered(&a))
	{
		if (ft_lstsize_node(a) <= 5)
			ft_tiny_stack(&a, &b);
		if (ft_lstsize_node(a) > 5)
			ft_push_swap(&a, &b);
	}
	ft_lstclear_node(&a);
}
