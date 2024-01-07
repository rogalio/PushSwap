/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogalio <rmouchel@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 11:18:29 by rogalio           #+#    #+#             */
/*   Updated: 2024/01/07 18:11:53 by rogalio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	handle_error_bonus(char **tab, t_stack **stack)
{
	if (tab)
		free_split(tab);
	if (stack && *stack)
		free_stack(stack);
	free_stack(stack);
	exit(1);
}

void	parse_one_arg2(char *str, t_stack **stack_a)
{
	char			**lst_of_ints;
	int				i;
	long int		value;

	lst_of_ints = ft_split(str, ' ');
	if (!lst_of_ints)
		handle_error_bonus(lst_of_ints, stack_a);
	i = 0;
	while (lst_of_ints[i])
	{
		if (!is_valid_number(lst_of_ints[i]))
			handle_error_bonus2(lst_of_ints, stack_a);
		value = ft_atoi(lst_of_ints[i]);
		if (value > INT_MAX || value < INT_MIN)
			handle_error_bonus2(lst_of_ints, stack_a);
		if (!add_value_to_stack(stack_a, value))
			handle_error_bonus2(lst_of_ints, stack_a);
		i++;
	}
	free_split(lst_of_ints);
	check_duplicates2(*stack_a);
	is_sorted2(*stack_a);
}

int	parse_args2(int ac, char **av, t_stack **stack_a)
{
	int			i;
	long int	value;

	i = 1;
	while (i < ac)
	{
		if (!is_valid_number(av[i]))
			handle_error_bonus(NULL, stack_a);
		value = ft_atoi(av[i]);
		if (value > INT_MAX || value < INT_MIN)
			handle_error_bonus(NULL, stack_a);
		if (!add_value_to_stack(stack_a, value))
			handle_error_bonus(NULL, stack_a);
		i++;
	}
	check_duplicates2(*stack_a);
	is_sorted2(*stack_a);
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

int	check_duplicates2(t_stack *stack_a)
{
	t_stack	*current;
	t_stack	*tmp;

	current = stack_a;
	while (current)
	{
		tmp = current->next;
		while (tmp)
		{
			if (current->value == tmp->value)
				handle_error_bonus(NULL, &stack_a);
			tmp = tmp->next;
		}
		current = current->next;
	}
	return (1);
}
