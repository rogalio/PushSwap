/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotations2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogalio <rmouchel@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 13:16:37 by rogalio           #+#    #+#             */
/*   Updated: 2024/01/07 16:22:47 by rogalio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rra(t_stack **stack_a)
{
	rotate_down(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **stack_b)
{
	rotate_down(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rotate_down(stack_a);
	rotate_down(stack_b);
	write(1, "rrr\n", 4);
}

void	rotate_to_top(t_stack **stack, int target_index, char stack_name)
{
	int	size;
	int	index_position;

	size = stack_size(*stack);
	index_position = get_index_in_stack(*stack, target_index);
	if (index_position == -1)
		return ;
	while ((*stack)->index != target_index)
	{
		if (index_position < size / 2)
		{
			if (stack_name == 'a')
				ra(stack);
			else
				rb(stack);
		}
		else
		{
			if (stack_name == 'a')
				rra(stack);
			else
				rrb(stack);
		}
		index_position = get_index_in_stack(*stack, target_index);
	}
}

int	get_position_in_sorted_stack(t_stack *stack, int target_index)
{
	int	position;

	position = 0;
	while (stack)
	{
		if (stack->index < target_index)
			position++;
		stack = stack->next;
	}
	return (position);
}
