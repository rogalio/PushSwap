/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogalio <rmouchel@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:44:08 by rogalio           #+#    #+#             */
/*   Updated: 2023/12/20 17:46:54 by rogalio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	find_optimized_median(t_stack **stack_a)
{
	int	size;
	int	i;
	int	median;
	int	*array;

	size = stack_size(*stack_a);
	array = malloc(sizeof(int) * size);
	if (!array)
		handle_error(0);
	i = 0;
	while (i < size)
	{
		array[i] = peek(*stack_a);
		ra(stack_a);
		i++;
	}
	sort_array(array, size);
	median = array[size / 2];
	free(array);
	return (median);
}

int	partition_around_pivot(t_stack **stack_a, t_stack **stack_b, int pivot)
{
	int	size;
	int	i;

	size = stack_size(*stack_a);
	i = 0;
	while (i < size)
	{
		if (peek(*stack_a) <= pivot)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
		i++;
	}
	return (size - stack_size(*stack_a));
}

int	sort_b_and_push_to_a(t_stack **stack_a, t_stack **stack_b)
{
	int	max;
	int	size;
	int	i;

	size = stack_size(*stack_b);
	i = 0;
	while (i < size)
	{
		max = find_max(*stack_b);
		while (peek(*stack_b) != max)
			rb(stack_b);
		pa(stack_a, stack_b);
	i++;
	}
	return (size);
}

void	quicksort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	pivot;

	while (stack_size(*stack_a) > 0)
	{
		pivot = find_optimized_median(stack_a);
		partition_around_pivot(stack_a, stack_b, pivot);
	}
	sort_b_and_push_to_a(stack_a, stack_b);
}

int	check_duplicates(t_stack *stack_a)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = stack_a;
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp->value == tmp2->value)
			{
				free_stack(&stack_a);
				handle_error(0);
			}
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (0);
}
