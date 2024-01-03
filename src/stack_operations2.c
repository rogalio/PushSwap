/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogalio <rmouchel@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 13:14:21 by rogalio           #+#    #+#             */
/*   Updated: 2024/01/03 13:15:04 by rogalio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sa(t_stack **stack_a)
{
	swap(stack_a);
	write(1, "sa\n", 3);
}

void	sb(t_stack **stack_b)
{
	swap(stack_b);
	write(1, "sb\n", 3);
}

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