/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogalio <rmouchel@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:12:10 by rogalio           #+#    #+#             */
/*   Updated: 2023/12/20 18:59:11 by rogalio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	is_sorted(t_stack *stack_a)
{
	t_stack	*current;

	current = stack_a;
	while (current->next)
	{
		if (current->value > current->next->value)
			return ;
		current = current->next;
	}
	free_stack(&stack_a);
	exit(EXIT_SUCCESS);
}

int	find_median_of_three(t_stack **stack_a)
{
	int	first;
	int	middle;
	int	last;

	first = peek(*stack_a);
	middle = get_element_at(*stack_a, stack_size(*stack_a) / 2);
	last = get_element_at(*stack_a, stack_size(*stack_a) - 1);
	if ((first > middle && first < last) || (first < middle && first > last))
		return (first);
	else if ((middle > first && middle < last)
		|| (middle < first && middle > last))
		return (middle);
	else if ((last > first && last < middle) || (last < first && last > middle))
		return (last);
	return (0);
}

void	move_median_to_top(t_stack **stack_a)
{
	int	median;
	int	position;
	int	size;

	median = find_median_of_three(stack_a);
	position = position_of(median, *stack_a);
	size = stack_size(*stack_a);
	while (peek(*stack_a) != median)
	{
		if (position <= size / 2)
			ra(stack_a);
		else
			rra(stack_a);
	}
}
