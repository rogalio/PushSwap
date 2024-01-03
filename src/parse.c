/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogalio <rmouchel@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:37:27 by rogalio           #+#    #+#             */
/*   Updated: 2024/01/03 13:20:08 by rogalio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	parse_input_arguments(int ac, char **av, t_stack **stack_a)
{
	if (ac < 2)
		exit(1);
	if (ac == 2)
		parse_one_arg(av[1], stack_a);
	else
		parse_args(ac, av, stack_a);
}

void	parse_one_arg(char *str, t_stack **stack_a)
{
	char	**lst_of_ints;
	int		i;
	long int		value;

	lst_of_ints = ft_split(str, ' ');
	if (!lst_of_ints)
		handle_error(lst_of_ints);
	i = 0;
	while (lst_of_ints[i])
	{
		if (!is_valid_number(lst_of_ints[i]))
			handle_error(lst_of_ints);
		value = ft_atoi(lst_of_ints[i]);
		if (value > INT_MAX || value < INT_MIN)
			handle_error(lst_of_ints);
		if (!add_value_to_stack(stack_a, value))
			handle_error(lst_of_ints);
		i++;
	}
	free_split(lst_of_ints);
	check_duplicates(*stack_a);
	is_sorted(*stack_a);
}

int	parse_args(int ac, char **av, t_stack **stack_a)
{
	int	i;
	long int	value;

	i = 1;
	while (i < ac)
	{
		if (!is_valid_number(av[i]))
			handle_error(0);
		value = ft_atoi(av[i]);
		if (value > INT_MAX || value < INT_MIN)
			handle_error(0);
		if (!add_value_to_stack(stack_a, value))
			handle_error(0);
		i++;
	}
	check_duplicates(*stack_a);
	is_sorted(*stack_a);
	return (1);
}

t_stack	*init_stack(void)
{
	return (NULL);
}
bool	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}
