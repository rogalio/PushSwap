/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogalio <rmouchel@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 13:11:04 by rogalio           #+#    #+#             */
/*   Updated: 2024/01/03 17:26:59 by rogalio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

void	sa(t_stack **stack_a)
{
	swap(stack_a);
	write(1, "sa\n", 3);
}

void	sb(t_stack **stack_b)
{
	swap(stack_b);
	write(1, "sb\n", 3);
}
