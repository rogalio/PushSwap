/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogalio <rmouchel@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:02:28 by rogalio           #+#    #+#             */
/*   Updated: 2023/12/18 18:03:29 by rogalio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

bool	is_empty(t_stack *stack)
{
	return (!stack);
}
