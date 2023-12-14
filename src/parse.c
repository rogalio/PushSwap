/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogalio <rmouchel@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:37:27 by rogalio           #+#    #+#             */
/*   Updated: 2023/12/14 17:43:43 by rogalio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	parse_input_arguments(int ac, char **av, t_stack **stack_a)
{
	if (ac < 2)
		handle_error(0, "not enough arguments");
	if (ac == 2)
		parse_one_arg(av[1], stack_a);
	else
		parse_args(ac, av, stack_a);
}

void	parse_one_arg(char *str, t_stack **stack_a)
{
	char	**lst_of_ints;
	int		i;
	int		value;

	lst_of_ints = ft_split(str, ' ');
	if (!lst_of_ints)
		handle_error(lst_of_ints, "split failed");
	i = 0;
	while (lst_of_ints[i])
	{
		if (!is_valid_number(lst_of_ints[i]))
			handle_error(lst_of_ints, "invalid number");
		value = ft_atoi(lst_of_ints[i]);
		if (!add_value_to_stack(stack_a, value))
			handle_error(lst_of_ints, "push failed");
		i++;
	}
	free_split(lst_of_ints);
}

int	parse_args(int ac, char **av, t_stack **stack_a)
{
	int	i;
	int	value;

	i = 1;
	while (i < ac)
	{
		if (!is_valid_number(av[i]))
			handle_error(0, "invalid number");
		value = ft_atoi(av[i]);
		if (!add_value_to_stack(stack_a, value))
			handle_error(0, "push failed");
		i++;
	}
	return (1);
}
