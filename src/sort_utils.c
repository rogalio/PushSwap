/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogalio <rmouchel@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:39:42 by rogalio           #+#    #+#             */
/*   Updated: 2024/01/03 18:33:51 by rogalio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void remove_specific(t_stack **stack_a, t_stack **stack_b, int value)
{
    int pos;
    
    pos = position_of(value, *stack_a);
    while ((*stack_a)->value != value)
    {
        if (pos < stack_size(*stack_a) / 2)
            ra(stack_a);
        else
            rra(stack_a);
    }
    pb(stack_a, stack_b);
}
void insert_in_order(t_stack **stack_a, t_stack **stack_b)
{
    pa(stack_a, stack_b);
    if ((*stack_a)->index > (*stack_a)->next->index)
        sa(stack_a);
}

int remove_min(t_stack **stack_a, t_stack **stack_b)
{
	int min ;
	int min_pos ;
	int size;

    min = find_min(*stack_a);
    min_pos = position_of(min, *stack_a);
    size = stack_size(*stack_a);
	while (min_pos--)
		ra(stack_a);
	pb(stack_a, stack_b);
	return size - 1;
}

int find_next_min(t_stack *stack, int min)
{
	int next_min;

    next_min = INT_MAX;
	while (stack)
    {
		if (stack->value < next_min && stack->value > min)
			next_min = stack->value;
		stack = stack->next;
	}
	return next_min;
}
t_chunk *calculate_ranges_of_chunks(int size, int chunk_size)
{
	int i;
	int j;
	int chunk_count;
	t_chunk *chunks;

	i = 0;
	j = 1;
	chunk_count = size / chunk_size;
	chunks = malloc(sizeof(t_chunk) * chunk_count);
	while (i < chunk_count)
	{
		chunks[i].start = j;
		chunks[i].end = j + chunk_size ;
		j += chunk_size;
		i++;
	}
	return (chunks);
}