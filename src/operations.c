/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogalio <rmouchel@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:20:42 by rogalio           #+#    #+#             */
/*   Updated: 2023/12/18 18:03:10 by rogalio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

bool	push(t_stack **stack, int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (false);
	new->value = value;
	new->next = *stack;
	*stack = new;
	return (true);
}

bool	pop(t_stack **stack)
{
	t_stack	*tmp;

	if (!*stack)
		return (false);
	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);
	return (true);
}

bool	swap(t_stack **stack)
{
	t_stack	*tmp;

	if (!*stack || !(*stack)->next)
		return (false);
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = *stack;
	*stack = tmp;
	return (true);
}

int	peek(t_stack *stack)
{
	if (!stack)
		return (0);
	return (stack->value);
}
