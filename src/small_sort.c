/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogalio <rmouchel@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 18:23:42 by rogalio           #+#    #+#             */
/*   Updated: 2024/01/03 13:26:06 by rogalio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void sort_two_elements(t_stack **stack_a)
{
	if ((*stack_a)->index > (*stack_a)->next->index)
		sa(stack_a);
}

void sort_three_elements(t_stack **stack_a) {
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

int remove_min(t_stack **stack_a, t_stack **stack_b) {
	int min = find_min(*stack_a);
	int min_pos = position_of(min, *stack_a);
	int size = stack_size(*stack_a);

	while (min_pos--) {
		ra(stack_a); // Rotation jusqu'à ce que le minimum soit en haut
	}
	pb(stack_a, stack_b); // Pousser le minimum dans stack_b

	return size - 1; // Retourne la nouvelle taille de stack_a
}

int find_next_min(t_stack *stack, int min) {
	int next_min = INT_MAX;

	while (stack) {
		if (stack->value < next_min && stack->value > min) {
			next_min = stack->value;
		}
		stack = stack->next;
	}

	return next_min;
}

void sort_four_elements(t_stack **stack_a, t_stack **stack_b) {
    // Trouvez les deux éléments les plus petits

    remove_min(stack_a, stack_b); // Poussez le premier min dans stack_b
	remove_min(stack_a, stack_b); // Poussez le second min dans stack_b
    
    // Triez les deux éléments restants dans stack_a
    sort_two_elements(stack_a);

    // Ramenez les éléments de stack_b
    pa(stack_a, stack_b); // Ramenez le second min
    pa(stack_a, stack_b); // Ramenez le premier min
}








