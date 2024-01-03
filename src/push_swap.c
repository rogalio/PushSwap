/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogalio <rmouchel@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:44:08 by rogalio           #+#    #+#             */
/*   Updated: 2024/01/03 18:42:57 by rogalio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int get_position(int *array, int size, int value)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (array[i] == value)
			return (i + 1);
		i++;
	}
	return (0);
}

void sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int size;

	size = stack_size(*stack_a);
	if (size == 2)
		sort_two_elements(stack_a);
	else if (size == 3)
		sort_three_elements(stack_a);
	else if (size == 4)
		sort_four_elements(stack_a, stack_b);
	else if (size == 5)
		sort_five_elements(stack_a, stack_b);
	else
		sort_large_elements(stack_a, stack_b);
}

int	main(int ac, char **av)
{
	t_stack		*stack_a;
	t_stack		*stack_b;

	stack_a = init_stack();
	stack_b = init_stack();
	parse_input_arguments(ac, av, &stack_a);
	index_stack(stack_a);
	sort_stack(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
