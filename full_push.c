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
    if (split[j] == '-')
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
t_node	*ft_lstlast_node(t_node **stack)
{
	t_node	*ult;

	ult = *stack;
	if (!stack)
		return (NULL);
	while (ult->next)
	{
		ult = ult->next;
	}
	return (ult);
}
//estionar si los nodos estan vacios y que no escriba
void    ft_push(t_node **a, t_node **b)
{
    t_node  *temp1;
    t_node  *temp2;
    // if (*a == NULL || *b == NULL)
    //     return;
    temp1 = *a;
    temp2 = *b;
    *a = (*a)->next;
    temp1->next = temp2;
    *b = temp1;   
}

void    ft_push_a(t_node **a, t_node **b)
{
    ft_push(a, b);
    write(1, "pa\n", 3);
}
void    ft_push_b(t_node **b, t_node **a)
{
    ft_push(b, a);
    write(1, "pb\n", 3);
}
void    ft_reverse_rotate(t_node **stack)
{
    t_node  *temp1;
    t_node  *temp2;

    temp2 = *stack;
    while (temp2->next->next)
        temp2 = temp2->next;
    temp1 = temp2->next;
    temp1->next = *stack;
    temp2->next = NULL;
    *stack = temp1;
}
void    ft_reverse_rotate_a(t_node **a)
{
    ft_reverse_rotate(a);
    write(1, "rra\n", 4);
}
void    ft_reverse_rotate_b(t_node **b)
{
    ft_reverse_rotate(b);
    write(1, "rrb\n", 4);
}
void    ft_reverse_rotate_ab(t_node **a, t_node **b)
{
    ft_reverse_rotate_a(a);
    ft_reverse_rotate_b(b);
    write(1, "rrr\n", 4);
}
void    ft_rotate(t_node **stack)
{
    t_node  *temp;
    t_node  *temp2;

    temp2 = (*stack)->next;
    temp =  ft_lstlast_node(stack);
    temp->next = *stack;
    (*stack)->next = NULL;
    *stack = temp2;
}
void    ft_rotate_a(t_node **a)
{
    ft_rotate(a);
    write(1, "ra\n", 3);
}
void    ft_rotate_b(t_node **b)
{
    ft_rotate(b);
    write(1, "rb\n", 3);
}
void    ft_rotate_ab(t_node **a, t_node **b)
{
    ft_rotate_a(a);
    ft_rotate_b(b);
    write(1, "rr\n", 3);
}
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
void    ft_swap(t_node **stack)
{
    t_node  *temp;

    temp = (*stack)->next;
    (*stack)->next = temp->next;
    temp->next = *stack;
    *stack = temp;
}

void    ft_swap_swap(t_node **a, t_node **b)
{
    ft_swap(a);
    ft_swap(b);
    write(1, "ss\n", 3);
}
void   ft_swap_a(t_node **a)
{
    ft_swap(a);
    write(1, "sa\n", 3);
}
void   ft_swap_b(t_node **b)
{
    ft_swap(b);
    write(1, "sb\n", 3);
}
#include "push_swap.h"

int ft_find_min(t_node *node)
{
    int i;
    int nb;
    t_node *head;

    i = 0;
    nb = INT_MAX;
    head = node;
    while (node)
    {
        if (nb > node->value)
        {
            nb = node->value;
        }
        node = node->next;
    }
    node = head;
    while (node)
    {
        if (nb == node->value)
        {
            printf("%d\n", i);
            return (i);
        }
        i++;
        node = node->next;
    }
    return (i);
}

 void   ft_three_stack(t_node **a)
 {
    if ((*a)->value > (*a)->next->value)
        ft_swap_a(a);
    if (!ft_check_ordered(a))
        return;
    if ((*a)->value < (*a)->next->value)
        ft_reverse_rotate_a(a);
    if ((*a)->value > (*a)->next->value)
        ft_swap_a(a);
 }

 void   ft_four_stack(t_node **a, t_node **b)
 {
    int i;
    
    i = ft_find_min(*a);
    while (i)
    {
        ft_rotate_a(a);
        i--;
    }
    ft_push_a(a, b);
    ft_three_stack(a);
    ft_push_b(b, a);
 }

 void   ft_five_stack(t_node **a, t_node **b)
 {
     int i;
    
    i = ft_find_min(*a);
    while (i)
    {
        ft_rotate_a(a);
        i--;
    }
    ft_push_a(a, b);
    ft_four_stack(a, b);
    ft_push_b(b, a);
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
    // Indice con el bit mas grande;
    int max_bits;
    int stack_size;

    ft_set_index(a);
    max_bits = ft_find_max_bits(a);
    stack_size = ft_lstsize_node(*a);
    while (stack_size--)
    {
        if (((*a)->index >> max_bits & 1) == 0)
        {
            ft_push_b(a, b);
        }
        else if (ft_check_ordered(a))
            return;
        else
            ft_rotate_b(a);
    }
    if (ft_check_ordered(a) == 1)
        ft_push_swap(a, b);
//  Llevarme todos los numeros binarios terminados en 0 a stack de b (PUSH A);
//  Volver a traerlos en al stack de A;
//  Repetir el proceso en bit por bit
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