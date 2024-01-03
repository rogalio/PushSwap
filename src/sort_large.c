/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogalio <rmouchel@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 12:01:59 by rogalio           #+#    #+#             */
/*   Updated: 2024/01/03 18:32:56 by rogalio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void distribute_elements_to_chunks(t_stack **stack_a, t_stack **stack_b, t_chunk *chunks, int total_chunks)
{
    int size;
    int pairs_to_process;
    int current_pair;
	s_process_chunk process_chunk;

	size = stack_size(*stack_a);
	current_pair = 0;
    if (total_chunks % 2 == 0)
        pairs_to_process = total_chunks;
    else
        pairs_to_process = total_chunks - 1;
    process_chunk.chunks = chunks;
    process_chunk.total_chunks = total_chunks;
    while (current_pair < pairs_to_process)
    {
        process_chunk.current_pair = current_pair;
        process_chunk_pair(stack_a, stack_b, &process_chunk, &size);
        current_pair += 2;
    }
    while (stack_size(*stack_a) > 0)
        pb(stack_a, stack_b);
}


void process_chunk_pair(t_stack **stack_a, t_stack **stack_b, s_process_chunk *process_chunk, int *size)
{
    int end_of_pair;

    if (process_chunk->current_pair + 1 < process_chunk->total_chunks)
        end_of_pair = process_chunk->chunks[process_chunk->current_pair + 1].end;
    else
        end_of_pair = *size;

    int i = 0;
    while (i < *size)
    {
        if ((*stack_a)->index >= process_chunk->chunks[process_chunk->current_pair].start && (*stack_a)->index <= end_of_pair)
        {
            pb(stack_a, stack_b);
            if (process_chunk->current_pair + 1 < process_chunk->total_chunks && (*stack_b)->index > process_chunk->chunks[process_chunk->current_pair].end)
                rb(stack_b);
        }
        else
            ra(stack_a);
        i++;
    }
    *size -= end_of_pair - process_chunk->chunks[process_chunk->current_pair].start + 1;
}


void move_chunks_to_a(t_stack **stack_a, t_stack **stack_b)
{
    int target_index;
    
    while (*stack_b)
    {
        target_index = find_highest_index(*stack_b);
        if (target_index == -1)
            break;
        rotate_to_top(stack_b, target_index, 'b');
        pa(stack_a, stack_b);
        insert_in_place(stack_a, target_index);
    }
}

void insert_in_place(t_stack **stack_a, int inserted_index)
{
    int size;
    int position_to_insert;
    
    size = stack_size(*stack_a);
    position_to_insert = get_position_in_sorted_stack(*stack_a, inserted_index);
    while ((*stack_a)->index != inserted_index)
    {
        if (position_to_insert < size / 2)
            ra(stack_a);
        else
            rra(stack_a);
    }
}

int sort_large_elements(t_stack **stack_a, t_stack **stack_b)
{
	int size;
	int chunk_size;
	t_chunk *chunks;

	size = stack_size(*stack_a);
	chunk_size = determine_chunk_size(size);
	chunks = calculate_ranges_of_chunks(size, chunk_size);
	distribute_elements_to_chunks(stack_a, stack_b, chunks, size / chunk_size);
	move_chunks_to_a(stack_a, stack_b);
	free(chunks);
	return (0);
}
