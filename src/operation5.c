/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogalio <rmouchel@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:09:38 by rogalio           #+#    #+#             */
/*   Updated: 2023/12/20 15:05:04 by rogalio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rotate_down(stack_a);
	rotate_down(stack_b);
	write(1, "rrr\n", 4);
}

int	stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

int	find_min(t_stack *stack)
{
	int	min;

	min = stack->value;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

int	find_max(t_stack *stack)
{
	int	max;

	max = stack->value;
	while (stack)
	{
		if (stack->value > max)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}

int	get_element_at(t_stack *stack, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		stack = stack->next;
		i++;
	}
	return (stack->value);
}
