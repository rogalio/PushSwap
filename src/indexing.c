/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogalio <rmouchel@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:34:29 by rogalio           #+#    #+#             */
/*   Updated: 2024/01/05 16:29:13 by rogalio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_index_in_stack(t_stack *stack, int target_index)
{
	int	position;

	position = 0;
	while (stack)
	{
		if (stack->index == target_index)
			return (position);
		stack = stack->next;
		position++;
	}
	return (-1);
}

int	find_highest_index(t_stack *stack)
{
	int	highest_index;
	int	highest_value;

	highest_index = 0;
	highest_value = INT_MIN;
	while (stack != NULL)
	{
		if (stack->index > highest_value)
		{
			highest_value = stack->index;
			highest_index = stack->index;
		}
		stack = stack->next;
	}
	return (highest_index);
}

int	find_min_index(t_stack *stack)
{
	int	min_index;
	int	min_value;
	int	index;

	min_index = 0;
	min_value = INT_MAX;
	index = 0;
	while (stack != NULL)
	{
		if (stack->index < min_value)
		{
			min_value = stack->index;
			min_index = index;
		}
		index++;
		stack = stack->next;
	}
	return (min_index);
}

int	*stack_to_array(t_stack *stack, int size)
{
	int	*array;
	int	i;

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

void	index_stack(t_stack *stack)
{
	int			size;
	int			*array;
	t_stack		*temp;

	temp = stack;
	size = stack_size(stack);
	array = stack_to_array(stack, size);
	sort_array(array, size);
	while (temp)
	{
		temp->index = get_position(array, size, temp->value);
		temp = temp->next;
	}
	free(array);
}
