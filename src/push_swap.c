/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogalio <rmouchel@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:44:08 by rogalio           #+#    #+#             */
/*   Updated: 2024/01/03 12:28:04 by rogalio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int size;

	size = stack_size(*stack_a);
	if (size == 2)
		sort_two_elements(stack_a);
	else if (size == 3)
		sort_three_elements(stack_a);
	else if (size == 4)
		sort_four_elements(stack_a, stack_b);
	else if (size == 5)
		sort_five_elements(stack_a, stack_b);
	else
		sort_large_elements(stack_a, stack_b);
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
