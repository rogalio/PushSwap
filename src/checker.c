/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogalio <rmouchel@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:45:52 by rogalio           #+#    #+#             */
/*   Updated: 2024/01/05 20:48:23 by rogalio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"




int get_next_line(int fd, char **line)
{
    char buf[2];
    char *tmp;
    int ret;

    if (!line || fd < 0 || read(fd, buf, 0) < 0)
        return (-1);
    *line = ft_strdup("");
    tmp = ft_strdup("");
    while ((ret = read(fd, buf, 1)) > 0 && buf[0] != '\n')
    {
        buf[ret] = '\0';
        tmp = ft_strjoin(*line, buf);
        free(*line);
        *line = tmp;
    }
    return (ret);
}

int ft_strcmp(char *s1, char *s2)
{
    int i;

    i = 0;
    while (s1[i])
    {
        if (s1[i] != s2[i])
            return (1);
        i++;
    }
    if (s2[i])
        return (1);
    return (0);
}


int check_if_sorted(t_stack *stack_a)
{
    t_stack *current;

    current = stack_a;
    while (current->next)
    {
        if (current->value > current->next->value)
            return (1);
        current = current->next;
    }
    return (0);
}

void sa1(t_stack **stack_a)
{
    t_stack *tmp;

    if (!*stack_a || !(*stack_a)->next)
        return ;
    tmp = (*stack_a)->next;
    (*stack_a)->next = (*stack_a)->next->next;
    tmp->next = *stack_a;
    *stack_a = tmp;
}
void sb1(t_stack **stack_b)
{
    t_stack *tmp;

    if (!*stack_b || !(*stack_b)->next)
        return ;
    tmp = (*stack_b)->next;
    (*stack_b)->next = (*stack_b)->next->next;
    tmp->next = *stack_b;
    *stack_b = tmp;
}

void ss1(t_stack **stack_a, t_stack **stack_b)
{
    sa(stack_a);
    sb(stack_b);
}

void pa1(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *tmp;

    if (!*stack_b)
        return ;
    tmp = *stack_b;
    *stack_b = (*stack_b)->next;
    tmp->next = *stack_a;
    *stack_a = tmp;
}

void pb1(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *tmp;

    if (!*stack_a)
        return ;
    tmp = *stack_a;
    *stack_a = (*stack_a)->next;
    tmp->next = *stack_b;
    *stack_b = tmp;
}

void ra1(t_stack **stack_a)
{
    t_stack *tmp;
    t_stack *current;

    if (!*stack_a || !(*stack_a)->next)
        return ;
    tmp = *stack_a;
    *stack_a = (*stack_a)->next;
    current = *stack_a;
    while (current->next)
        current = current->next;
    current->next = tmp;
    tmp->next = NULL;
}

void rb1(t_stack **stack_b)
{
    t_stack *tmp;
    t_stack *current;

    if (!*stack_b || !(*stack_b)->next)
        return ;
    tmp = *stack_b;
    *stack_b = (*stack_b)->next;
    current = *stack_b;
    while (current->next)
        current = current->next;
    current->next = tmp;
    tmp->next = NULL;
}

void rr1(t_stack **stack_a, t_stack **stack_b)
{
    ra(stack_a);
    rb(stack_b);
}

void rra1(t_stack **stack_a)
{
    t_stack *tmp;
    t_stack *current;

    if (!*stack_a || !(*stack_a)->next)
        return ;
    current = *stack_a;
    while (current->next->next)
        current = current->next;
    tmp = current->next;
    current->next = NULL;
    tmp->next = *stack_a;
    *stack_a = tmp;
}

void rrb1(t_stack **stack_b)
{
    t_stack *tmp;
    t_stack *current;

    if (!*stack_b || !(*stack_b)->next)
        return ;
    current = *stack_b;
    while (current->next->next)
        current = current->next;
    tmp = current->next;
    current->next = NULL;
    tmp->next = *stack_b;
    *stack_b = tmp;
}

void rrr1(t_stack **stack_a, t_stack **stack_b)
{
    rra(stack_a);
    rrb(stack_b);
}

int handle_error3(char **tab,t_stack **stack)
{
    (void)tab;
    if (stack && *stack)
        free_stack(stack);
    free_stack(stack);
    write(2, "OK\n", 3);
    exit(1);
}

int handle_error4(char **tab)
{
    (void)tab;
    write(2, "OK\n", 3);
    exit(1);
}

void	parse_one_arg2(char *str, t_stack **stack_a)
{
	char	**lst_of_ints;
	int		i;
	long int		value;

	lst_of_ints = ft_split(str, ' ');
	if (!lst_of_ints)
		handle_error4(lst_of_ints);
	i = 0;
	while (lst_of_ints[i])
	{
		if (!is_valid_number(lst_of_ints[i]))
		{
			free_stack(stack_a);
			handle_error4(lst_of_ints);
		}
		value = ft_atoi(lst_of_ints[i]);
		if (value > INT_MAX || value < INT_MIN)
		{
			free_stack(stack_a);
			handle_error4(lst_of_ints);
		}
		if (!add_value_to_stack(stack_a, value))
			handle_error4(lst_of_ints);
		i++;
	}
	free_split(lst_of_ints);
}


int	parse_args2(int ac, char **av, t_stack **stack_a)
{
	int	i;
	long int	value;

	i = 1;
	while (i < ac)
	{
		if (!is_valid_number(av[i]))
		{
			handle_error3(av,stack_a);
		}
		value = ft_atoi(av[i]);
		if (value > INT_MAX || value < INT_MIN)
		{
			handle_error3(av,stack_a);
		}
		if (!add_value_to_stack(stack_a, value))
			handle_error4(0);
		i++;
	}
	return (1);
}



void	parse_input_arguments2(int ac, char **av, t_stack **stack_a)
{
	if (ac < 2)
		exit(1);
	if (ac == 2)
		parse_one_arg2(av[1], stack_a);
	else
		parse_args2(ac, av, stack_a);
}





int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;
    char *line;
   int is_sorted;
   int is_duplicated;
   //int is_sorted2;
   (void)is_duplicated;


    stack_a = init_stack();
    stack_b = init_stack();
    parse_input_arguments2(argc, argv, &stack_a);
    index_stack(stack_a);
    while (get_next_line(0, &line) > 0)
    {
        if (ft_strcmp(line, "sa") == 0)
            sa1(&stack_a);
        else if (ft_strcmp(line, "sb") == 0)
            sb1(&stack_b);
        else if (ft_strcmp(line, "ss") == 0)
            ss1(&stack_a, &stack_b);
        else if (ft_strcmp(line, "pa") == 0)
            pa1(&stack_a, &stack_b);
        else if (ft_strcmp(line, "pb") == 0)
            pb1(&stack_a, &stack_b);
        else if (ft_strcmp(line, "ra") == 0)
            ra1(&stack_a);
        else if (ft_strcmp(line, "rb") == 0)
            rb1(&stack_b);
        else if (ft_strcmp(line, "rr") == 0)
            rr1(&stack_a, &stack_b);
        else if (ft_strcmp(line, "rra") == 0)
            rra1(&stack_a);
        else if (ft_strcmp(line, "rrb") == 0)
            rrb1(&stack_b);
        else if (ft_strcmp(line, "rrr") == 0)
            rrr1(&stack_a, &stack_b);

        free(line);
    }

    is_sorted = check_if_sorted(stack_a);
        if (is_sorted == 0 && stack_size(stack_b) == 0)
        {
            free_stack(&stack_a);
            free_stack(&stack_b);
            write(1, "OK\n", 3);
            return (0);
        }
        else if (is_sorted == 1 && stack_size(stack_b) == 0)
        {
            free_stack(&stack_a);
            free_stack(&stack_b);
            write(1, "KO\n", 3);
            return (0);
        }
    
    return (0);
}