/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotations2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogalio <rmouchel@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 13:16:37 by rogalio           #+#    #+#             */
/*   Updated: 2024/01/03 13:17:46 by rogalio          ###   ########.fr       */
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
int find_min(t_stack *stack)
{
	int min;
	t_stack *tmp;

	tmp = stack;
	min = tmp->value;
	while (tmp)
	{
		if (tmp->value < min)
			min = tmp->value;
		tmp = tmp->next;
	}
	return (min);
}