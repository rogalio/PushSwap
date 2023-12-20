/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogalio <rmouchel@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 18:23:42 by rogalio           #+#    #+#             */
/*   Updated: 2023/12/18 18:12:49 by rogalio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_two(t_stack **stack_a)
{
	int	a;
	int	b;

	a = peek(*stack_a);
	b = peek((*stack_a)->next);
	if (a > b)
		sa(stack_a);
}

void	sort_tree(t_stack **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = peek(*stack_a);
	b = peek((*stack_a)->next);
	c = peek((*stack_a)->next->next);
	if (a > b && b < c && a < c)
		sa(stack_a);
	else if (a > b && b > c && a > c)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (a > b && b < c && a > c)
		ra(stack_a);
	else if (a < b && b > c && a < c)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (a < b && b > c && a > c)
		rra(stack_a);
}

void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	int	min;

	min = find_min(*stack_a);
	while (peek(*stack_a) != min)
		ra(stack_a);
	pb(stack_a, stack_b);
	sort_tree(stack_a);
	pa(stack_a, stack_b);
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	min;

	min = find_min(*stack_a);
	while (peek(*stack_a) != min)
		ra(stack_a);
	pb(stack_a, stack_b);
	sort_four(stack_a, stack_b);
	pa(stack_a, stack_b);
}

int	position_of(int value, t_stack *stack_a)
{
	int	i;

	i = 0;
	while (stack_a)
	{
		if (stack_a->value == value)
			return (i);
		stack_a = stack_a->next;
		i++;
	}
	return (-1);
}
