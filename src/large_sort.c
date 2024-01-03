/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogalio <rmouchel@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 12:01:59 by rogalio           #+#    #+#             */
/*   Updated: 2024/01/03 13:30:45 by rogalio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"




int determine_chunk_size(int size)
{
	if (size <= 50)
		return (size / 2);
	else if (size <= 100)
		return (size / 6);
	else
		return (size / 16);
}

void sort_chunk_in_a(t_stack **stack_a) {
    int size = stack_size(*stack_a);

    // Cas avec deux éléments
    if (size == 2) {
        if ((*stack_a)->index > (*stack_a)->next->index) {
            sa(stack_a); // Échange les deux éléments
        }
    }

    // Cas avec trois éléments
    else if (size == 3) {
		int first_index = (*stack_a)->index;
		int second_index = (*stack_a)->next->index;
		int third_index = (*stack_a)->next->next->index;

		if (first_index > second_index && first_index < third_index) {
			sa(stack_a); // Échange les deux premiers éléments
		} else if (first_index > second_index && first_index > third_index) {
			sa(stack_a); // Échange les deux premiers éléments
			rra(stack_a); // Tourne vers le bas
		} else if (first_index < second_index && first_index > third_index) {
			ra(stack_a); // Tourne vers le haut
		} else if (first_index < second_index && first_index < third_index) {
			rra(stack_a); // Tourne vers le bas
		}
	}
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



t_chunk *calculate_ranges_of_chunks(int size, int chunk_size) {
	int i;
	int j;
	int chunk_count;
	t_chunk *chunks;

	i = 0;
	j = 1;
	chunk_count = size / chunk_size;
	chunks = malloc(sizeof(t_chunk) * chunk_count);
	while (i < chunk_count) {
		chunks[i].start = j;
		chunks[i].end = j + chunk_size ;
		j += chunk_size;
		i++;
	}
	return (chunks);
}

int sort_large_elements(t_stack **stack_a, t_stack **stack_b) {
	int size;
	int chunk_size;
	t_chunk *chunks;

	size = stack_size(*stack_a);
	chunk_size = determine_chunk_size(size);
	chunks = calculate_ranges_of_chunks(size, chunk_size);
	distribute_elements_to_chunks(stack_a, stack_b, chunks, size / chunk_size);
	sort_chunk_in_a(stack_a);
	move_chunks_to_a(stack_a, stack_b);
	finalize_stack_a(stack_a);
	free(chunks);

	return (0);
}
