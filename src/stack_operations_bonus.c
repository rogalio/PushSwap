/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogalio <rmouchel@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 11:16:20 by rogalio           #+#    #+#             */
/*   Updated: 2024/01/06 11:47:17 by rogalio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void pb1(t_stack **stack_a, t_stack **stack_b)
{
    if (stack_a == NULL || *stack_a == NULL) {
        return; // Vérifiez si la pile A est vide
    }

    t_stack *temp = *stack_a; // Sauvegardez le nœud en haut de la pile A
    *stack_a = (*stack_a)->next; // Retirez le nœud du sommet de la pile A

    temp->next = *stack_b; // Placez le nœud au sommet de la pile B
    *stack_b = temp; // Mettez à jour le sommet de la pile B
}

void pa1(t_stack **stack_a, t_stack **stack_b)
{
    if (stack_b == NULL || *stack_b == NULL) {
        return; // Vérifiez si la pile B est vide
    }

    t_stack *temp = *stack_b; // Sauvegardez le nœud en haut de la pile B
    *stack_b = (*stack_b)->next; // Retirez le nœud du sommet de la pile B

    temp->next = *stack_a; // Placez le nœud au sommet de la pile A
    *stack_a = temp; // Mettez à jour le sommet de la pile A
}

void ss1(t_stack **stack_a, t_stack **stack_b)
{
    sa(stack_a);
    sb(stack_b);
}

void rr1(t_stack **stack_a, t_stack **stack_b)
{
    ra(stack_a);
    rb(stack_b);
}

void rrr1(t_stack **stack_a, t_stack **stack_b)
{
    rra(stack_a);
    rrb(stack_b);
}

int check_duplicates2(t_stack *stack_a)
{
    t_stack *current;
    t_stack *tmp;

    current = stack_a;
    while (current)
    {
        tmp = current->next;
        while (tmp)
        {
            if (current->value == tmp->value)
                handle_error_bonus(NULL, &stack_a);
            tmp = tmp->next;
        }
        current = current->next;
    }
    return (1);
}
