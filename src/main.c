/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogalio <rmouchel@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:00:41 by rmouchel          #+#    #+#             */
/*   Updated: 2024/01/02 19:24:49 by rogalio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"






t_stack	*init_stack(void)
{
	return (NULL);
}






int is_sorted2(t_stack *stack_a)
{
	t_stack *tmp;

	tmp = stack_a;
	while (tmp->next)
	{
		if (tmp->index > tmp->next->index)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}




t_stack *get_element_at2(t_stack *stack, int index) {
	t_stack *current = stack;
	int count = 0;
	while (current != NULL) {
		if (count == index)
			return (current);
		count++;
		current = current->next;
	}
	return (NULL);
}





void display_stack(t_stack *stack)
{
	while (stack)
	{
		printf("index = %d 	and value = %d\n", stack->index, stack->value);
		stack = stack->next;
	}
}



int find_max_index(t_stack *stack) {
	int max_index = 0;
	int max_value = INT_MIN;
	int index = 0;

	while (stack != NULL) {
		if (stack->index > max_value) {
			max_value = stack->index;
			max_index = index;
		}
		index++;
		stack = stack->next;
	}

	return (max_index);
}

int find_min_index(t_stack *stack) {
	int min_index = 0;
	int min_value = INT_MAX;
	int index = 0;

	while (stack != NULL) {
		if (stack->index < min_value) {
			min_value = stack->index;
			min_index = index;
		}
		index++;
		stack = stack->next;
	}

	return (min_index);
}


// index
int *stack_to_array(t_stack *stack, int size)
{
	int *array;
	int i;

	i = 0;
	array = malloc(sizeof(int) * size);
	while (stack)
	{
		array[i] = stack->value;
		stack = stack->next;
		i++;
	}
	return (array);
}

int get_position(int *array, int size, int value)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (array[i] == value)
			return (i + 1);
		i++;
	}
	return (0);
}

void index_stack(t_stack *stack)
{
	int size;
	int *array;
	t_stack *temp;

	temp = stack;
	size = stack_size(stack);
	array = stack_to_array(stack, size);
	sort_array(array, size);
	while (temp)
	{
        temp->index = get_position(array, size, temp->value);
        temp = temp->next;
    }
	free(array);
}

typedef struct s_chunk {
    int start;
    int end;
} t_chunk;

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


void move_elements_to_b(t_stack **stack_a, t_stack **stack_b, t_chunk *chunks, int total_chunks) {
    int size = stack_size(*stack_a);
    int pairs_to_process = (total_chunks % 2 == 0) ? total_chunks : total_chunks - 1;

    for (int current_pair = 0; current_pair < pairs_to_process; current_pair += 2) {
        int end_of_pair = (current_pair + 1 < total_chunks) ? chunks[current_pair + 1].end : size;

        for (int i = 0; i < size; i++) {
            if ((*stack_a)->index >= chunks[current_pair].start && (*stack_a)->index <= end_of_pair) {
                pb(stack_a, stack_b);
                if (current_pair + 1 < total_chunks && (*stack_b)->index > chunks[current_pair].end) {
                    rb(stack_b);
                }
            } else {
                ra(stack_a);
            }
        }
        size -= end_of_pair - chunks[current_pair].start + 1;
    }

    // Gérer les éléments restants dans stack_a
    while (stack_size(*stack_a) > 0) {
        pb(stack_a, stack_b);
    }
}




/*
void move_elements_to_b(t_stack **stack_a, t_stack **stack_b, t_chunk *chunks, int total_chunks) {
    int current_chunk = 0;
    int size = stack_size(*stack_a);

    while (current_chunk <= total_chunks) {
        for (int i = 0; i < size; i++) {
            if ((*stack_a)->index >= chunks[current_chunk].start && (*stack_a)->index <= chunks[current_chunk].end) {
                pb(stack_a, stack_b); // Push l'élément de A à B.

                // Si l'élément appartient au deuxième chunk, faire un 'rb'.
                if (current_chunk == 1) {
                    rb(stack_b);
                }
            } else {
                ra(stack_a); // Rotate A si l'élément n'appartient pas au chunk.
            }
        }
        current_chunk++;

        // Si on a fini avec les deux premiers chunks, on arrête.
        if (current_chunk == total_chunks - 1) {
            break;
        }
    }
}

*/

int find_highest_index(t_stack *stack) {
	int highest_index = 0;
	int highest_value = INT_MIN;

	while (stack != NULL) {
		if (stack->index > highest_value) {
			highest_value = stack->index;
			highest_index = stack->index;
		}
		stack = stack->next;
	}

	return highest_index;
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




int get_index_in_stack(t_stack *stack, int target_index) {
    int position = 0;

    while (stack) {
        if (stack->index == target_index) {
            return position;
        }
        stack = stack->next;
        position++;
    }

    return -1; // Retourne -1 si l'index n'est pas trouvé
}

int find_next_target_in_b(t_stack *stack_a, t_stack *stack_b) {
    if (!stack_a) return find_min_index(stack_b); // Si stack_a est vide, retourne l'index minimum dans stack_b

    int next_target = INT_MAX;
    t_stack *current_b = stack_b;
    while (current_b) {
        if (current_b->index > stack_a->index && current_b->index < next_target) {
            next_target = current_b->index;
        }
        current_b = current_b->next;
    }

    return next_target == INT_MAX ? -1 : next_target; // Retourne -1 si aucun élément n'est trouvé
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

void finalize_stack_a(t_stack **stack_a) {
    int min_index = find_min_index(*stack_a);
    rotate_to_top(stack_a, min_index, 'a');
}




void chunk_stack(t_stack **stack_a, t_stack **stack_b) {
    int size = stack_size(*stack_a);
    int chunk_size;

    if (size <= 50)
        chunk_size = size / 2; // Deux chunks pour les petites piles.
    else if (size <= 100)
        chunk_size = size / 6; // Trois chunks pour les piles de taille moyenne.
    else
        chunk_size = size / 16; // Cinq chunks pour les grandes piles.
		
	t_chunk *chunks = calculate_ranges_of_chunks(size, chunk_size);
	move_elements_to_b(stack_a, stack_b, chunks, size / chunk_size);

	 sort_chunk_in_a(stack_a); // Triez le chunk dans stack_a
    move_chunks_to_a(stack_a, stack_b); // Ramenez et triez les chunks de stack_b
    finalize_stack_a(stack_a); // Ajustez stack_a à la fin


	free(chunks);
}



/// sort small :: 
void sort_two_elements(t_stack **stack_a)
{
	if ((*stack_a)->index > (*stack_a)->next->index)
		sa(stack_a);
}

void sort_three_elements(t_stack **stack_a) {
    int first = (*stack_a)->index;
    int second = (*stack_a)->next->index;
    int third = (*stack_a)->next->next->index;

    if (first > second && second < third && first < third) sa(stack_a); // Cas 1
    else if (first > second && second > third) { sa(stack_a); rra(stack_a); } // Cas 2
    else if (first > second && second < third && first > third) ra(stack_a); // Cas 3
    else if (first < second && second > third && first < third) { sa(stack_a); ra(stack_a); } // Cas 4
    else if (first < second && second > third && first > third) rra(stack_a); // Cas 5
    // Cas 6 est déjà trié
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

int determine_chunk_size(int size)
{
	if (size <= 50)
		return (size / 2);
	else if (size <= 100)
		return (size / 6);
	else
		return (size / 16);
}

typedef struct s_process_chunk {
    t_chunk *chunks;
    int current_pair;
    int total_chunks;
} s_process_chunk;

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

void sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int size;

	size = stack_size(*stack_a);
	if (size == 2)
		sort_two_elements(stack_a);
	else if (size == 3)
		sort_three_elements(stack_a);
	else if (size == 4)
		sort_four_elements(stack_a, stack_b);
	else if (size == 5)
		sort_five_elements(stack_a, stack_b);
	else
		sort_large_elements(stack_a, stack_b);
}

int	main(int ac, char **av)
{
	t_stack		*stack_a;
	t_stack		*stack_b;

	stack_a = init_stack();
	stack_b = init_stack();
	parse_input_arguments(ac, av, &stack_a);
	index_stack(stack_a);
	sort_stack(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
