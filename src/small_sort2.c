/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogalio <rmouchel@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 13:25:02 by rogalio           #+#    #+#             */
/*   Updated: 2024/01/03 13:26:17 by rogalio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

void remove_specific(t_stack **stack_a, t_stack **stack_b, int value) {
    int pos = position_of(value, *stack_a);

    while ((*stack_a)->value != value) {
        if (pos < stack_size(*stack_a) / 2) {
            ra(stack_a);
        } else {
            rra(stack_a);
        }
    }
    pb(stack_a, stack_b);
}

void insert_in_order(t_stack **stack_a, t_stack **stack_b) {
    pa(stack_a, stack_b); // Récupérer un élément de stack_b
    if ((*stack_a)->index > (*stack_a)->next->index) {
        sa(stack_a); // Si nécessaire, échanger les deux éléments en haut de stack_a
    }
}

void sort_five_elements(t_stack **stack_a, t_stack **stack_b) {
    int first_min, second_min;

    // Trouver les deux plus petits éléments
    first_min = find_min(*stack_a);
    remove_specific(stack_a, stack_b, first_min); // Supprimer le premier min de stack_a et le pousser dans stack_b
    second_min = find_next_min(*stack_a, first_min);
    remove_specific(stack_a, stack_b, second_min); // Supprimer le second min de stack_a et le pousser dans stack_b
    
    // Trier les trois éléments restants dans stack_a
    sort_three_elements(stack_a);

    // Récupérer et insérer correctement les deux éléments de stack_b dans stack_a
    insert_in_order(stack_a, stack_b); // Insérer le second min
    insert_in_order(stack_a, stack_b); // Insérer le premier min
}