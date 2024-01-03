/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogalio <rmouchel@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:12:10 by rogalio           #+#    #+#             */
/*   Updated: 2024/01/03 12:45:08 by rogalio          ###   ########.fr       */
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

