/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogalio <rmouchel@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 13:14:21 by rogalio           #+#    #+#             */
/*   Updated: 2024/01/03 18:23:31 by rogalio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"



void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_b == NULL || *stack_b == NULL) {
		return; // Vérifiez si la pile B est vide
	}

	t_stack *temp = *stack_b; // Sauvegardez le nœud en haut de la pile B
	*stack_b = (*stack_b)->next; // Retirez le nœud du sommet de la pile B

	temp->next = *stack_a; // Placez le nœud au sommet de la pile A
	*stack_a = temp; // Mettez à jour le sommet de la pile A
	write(1, "pa\n", 3);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a == NULL || *stack_a == NULL) {
        return; // Vérifiez si la pile A est vide
    }

    t_stack *temp = *stack_a; // Sauvegardez le nœud en haut de la pile A
    *stack_a = (*stack_a)->next; // Retirez le nœud du sommet de la pile A

    temp->next = *stack_b; // Placez le nœud au sommet de la pile B
    *stack_b = temp; // Mettez à jour le sommet de la pile B
	write(1, "pb\n", 3);
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

bool	add_value_to_stack(t_stack **stack, int value)
{
	t_stack	*new;
	t_stack	*current;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (false);
	new->value = value;
	new->next = NULL;
	if (!*stack)
		*stack = new;
	else
	{
		current = *stack;
		while (current->next)
			current = current->next;
		current->next = new;
	}
	return (true);
}