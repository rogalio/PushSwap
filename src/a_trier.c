/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_trier.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogalio <rmouchel@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:46:22 by rogalio           #+#    #+#             */
/*   Updated: 2024/01/03 14:54:18 by rogalio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

bool	rotate_up(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return (false);
	tmp = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	*stack = tmp->next;
	tmp->next = NULL;
	last->next = tmp;
	return (true);
}

bool	rotate_down(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return (false);
	tmp = *stack;
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	last->next = *stack;
	*stack = last;
	return (true);
}

bool	add_value_to_stack(t_stack **stack, int value)
{
	t_stack	*new;
	t_stack	*current;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (false);
	new->value = value;
	new->next = NULL;
	if (!*stack)
		*stack = new;
	else
	{
		current = *stack;
		while (current->next)
			current = current->next;
		current->next = new;
	}
	return (true);
}