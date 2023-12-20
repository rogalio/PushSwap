/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogalio <rmouchel@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:07:37 by rogalio           #+#    #+#             */
/*   Updated: 2023/12/20 15:03:30 by rogalio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ra(t_stack **stack_a)
{
	rotate_up(stack_a);
	write(1, "ra\n", 3);
}

void	rb(t_stack **stack_b)
{
	rotate_up(stack_b);
	write(1, "rb\n", 3);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate_up(stack_a);
	rotate_up(stack_b);
	write(1, "rr\n", 3);
}

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
