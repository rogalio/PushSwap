/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogalio <rmouchel@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:09:38 by rogalio           #+#    #+#             */
/*   Updated: 2024/01/03 12:41:25 by rogalio          ###   ########.fr       */
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


