/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogalio <rmouchel@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 18:23:42 by rogalio           #+#    #+#             */
/*   Updated: 2024/01/02 19:59:58 by rogalio          ###   ########.fr       */
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
