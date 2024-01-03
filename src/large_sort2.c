/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogalio <rmouchel@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 13:28:40 by rogalio           #+#    #+#             */
/*   Updated: 2024/01/03 13:30:31 by rogalio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void insert_in_place(t_stack **stack_a, int inserted_index) {
    int size = stack_size(*stack_a);
    int position_to_insert = get_position_in_sorted_stack(*stack_a, inserted_index);
    
    while ((*stack_a)->index != inserted_index) {
        if (position_to_insert < size / 2) {
            ra(stack_a); // Tourne vers le haut
        } else {
            rra(stack_a); // Tourne vers le bas
        }
    }
}

void move_chunks_to_a(t_stack **stack_a, t_stack **stack_b) {
    while (*stack_b) {
        int target_index = find_highest_index(*stack_b);
        if (target_index == -1) break;

        rotate_to_top(stack_b, target_index, 'b');
        pa(stack_a, stack_b);
        insert_in_place(stack_a, target_index);
    }
}

void rotate_to_top(t_stack **stack, int target_index, char stack_name) {
    // Vérifier que target_index existe dans la pile
    if (get_index_in_stack(*stack, target_index) == -1) return;

    int size = stack_size(*stack);
    int index_position = get_index_in_stack(*stack, target_index);

    while ((*stack)->index != target_index) {
        if (index_position < size / 2) {
            (stack_name == 'a') ? ra(stack) : rb(stack);
        } else {
            (stack_name == 'a') ? rra(stack) : rrb(stack);
        }
        index_position = get_index_in_stack(*stack, target_index);
    }
}

void finalize_stack_a(t_stack **stack_a) {
    int min_index = find_min_index(*stack_a);
    rotate_to_top(stack_a, min_index, 'a');
}

int get_position_in_sorted_stack(t_stack *stack, int target_index) {
	int position = 0;

	while (stack) {
		if (stack->index < target_index) {
			position++;
		}
		stack = stack->next;
	}

	return position;
}