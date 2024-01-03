/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogalio <rmouchel@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:00:41 by rmouchel          #+#    #+#             */
/*   Updated: 2024/01/03 12:31:52 by rogalio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"


t_stack	*init_stack(void)
{
	return (NULL);
}

int is_sorted2(t_stack *stack_a)
{
	t_stack *tmp;

	tmp = stack_a;
	while (tmp->next)
	{
		if (tmp->index > tmp->next->index)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

t_stack *get_element_at2(t_stack *stack, int index) {
	t_stack *current = stack;
	int count = 0;
	while (current != NULL) {
		if (count == index)
			return (current);
		count++;
		current = current->next;
	}
	return (NULL);
}

void display_stack(t_stack *stack)
{
	while (stack)
	{
		printf("index = %d 	and value = %d\n", stack->index, stack->value);
		stack = stack->next;
	}
}

int *stack_to_array(t_stack *stack, int size)
{
	int *array;
	int i;

	i = 0;
	array = malloc(sizeof(int) * size);
	while (stack)
	{
		array[i] = stack->value;
		stack = stack->next;
		i++;
	}
	return (array);
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
