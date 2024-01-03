/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogalio <rmouchel@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 12:12:45 by rogalio           #+#    #+#             */
/*   Updated: 2024/01/03 13:23:31 by rogalio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void index_stack(t_stack *stack)
{
	int size;
	int *array;
	t_stack *temp;

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

int find_min_index(t_stack *stack) {
	int min_index = 0;
	int min_value = INT_MAX;
	int index = 0;

	while (stack != NULL) {
		if (stack->index < min_value) {
			min_value = stack->index;
			min_index = index;
		}
		index++;
		stack = stack->next;
	}

	return (min_index);
}

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

int get_index_in_stack(t_stack *stack, int target_index) {
    int position = 0;

    while (stack) {
        if (stack->index == target_index) {
            return position;
        }
        stack = stack->next;
        position++;
    }

    return -1; // Retourne -1 si l'index n'est pas trouvé
}

int find_highest_index(t_stack *stack) {
	int highest_index = 0;
	int highest_value = INT_MIN;

	while (stack != NULL) {
		if (stack->index > highest_value) {
			highest_value = stack->index;
			highest_index = stack->index;
		}
		stack = stack->next;
	}

	return highest_index;
}

