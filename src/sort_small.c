/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogalio <rmouchel@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 18:23:42 by rogalio           #+#    #+#             */
/*   Updated: 2024/01/03 17:35:37 by rogalio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void sort_two_elements(t_stack **stack_a)
{
	if ((*stack_a)->index > (*stack_a)->next->index)
		sa(stack_a);
}

void sort_three_elements(t_stack **stack_a)
{
    int first;
    int second;
    int third;

	first = (*stack_a)->index;
	second = (*stack_a)->next->index;
	third = (*stack_a)->next->next->index;
    if (first > second && second < third && first < third)
		sa(stack_a);
    else if (first > second && second > third)
	{	sa(stack_a);
		rra(stack_a);
	}
    else if (first > second && second < third && first > third)
		ra(stack_a);
    else if (first < second && second > third && first < third)
	{
		sa(stack_a);
		ra(stack_a);
	}
    else if (first < second && second > third && first > third)
		rra(stack_a);
}

void sort_four_elements(t_stack **stack_a, t_stack **stack_b) {
    remove_min(stack_a, stack_b);
	remove_min(stack_a, stack_b);
    sort_two_elements(stack_a);
    pa(stack_a, stack_b);
    pa(stack_a, stack_b);
}

void sort_five_elements(t_stack **stack_a, t_stack **stack_b) {
    int first_min;
	int second_min;

    first_min = find_min(*stack_a);
    remove_specific(stack_a, stack_b, first_min); 
    second_min = find_next_min(*stack_a, first_min);
    remove_specific(stack_a, stack_b, second_min); 
    sort_three_elements(stack_a);
    insert_in_order(stack_a, stack_b);
    insert_in_order(stack_a, stack_b);
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













