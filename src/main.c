/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogalio <rmouchel@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:00:41 by rmouchel          #+#    #+#             */
/*   Updated: 2023/12/27 18:01:33 by rogalio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*init_stack(void)
{
	return (NULL);
}

void	sort_small(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = stack_size(*stack_a);
	if (size == 1)
		return ;
	else if (size == 2)
		sort_two(stack_a);
	else if (size == 3)
		sort_tree(stack_a);
	else if (size == 4)
		sort_four(stack_a, stack_b);
	else if (size == 5)
		sort_five(stack_a, stack_b);
	else if (size > 5)
		quicksort_stack(stack_a, stack_b);
}

int get_index(int *array, int size, int value)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (array[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

void index_stack(t_stack **stack_a)
{
	int size;
	int *array;
	t_stack *tmp;
	int i;

	size = stack_size(*stack_a);
	array = malloc(sizeof(int) * size);
	tmp = *stack_a;
	i = 0;
	while (tmp)
	{
		array[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
	sort_array(array, size);
	tmp = *stack_a;
	while (tmp)
	{
		tmp->index = get_index(array, size, tmp->value);
		tmp = tmp->next;
	}
	free(array);
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



void merge_stacks(t_stack **stack_a, t_stack **stack_b) {
    if (is_empty(*stack_b)) {
        return; // Rien à faire si B est vide
    }

    if (is_empty(*stack_a)) {
        *stack_a = *stack_b; // Si A est vide, juste définir A à B
        *stack_b = NULL;
        return;
    }

    // Trouver le dernier élément de la pile A
    t_stack *last_a = *stack_a;
    while (last_a->next != NULL) {
        last_a = last_a->next;
    }

    // Attacher la pile B à la fin de la pile A
    last_a->next = *stack_b;
    *stack_b = NULL; // La pile B est maintenant vide
}





void display_stack(t_stack *stack)
{
	while (stack)
	{
		printf("index = %d 	and value = %d\n", stack->index, stack->value);
		stack = stack->next;
	}
}

void insert_sort_stack_a(t_stack **stack_a) {
    if (is_empty(*stack_a) || stack_size(*stack_a) == 1) {
        return; // Pas besoin de trier si A est vide ou a un seul élément.
    }

    t_stack *sorted = NULL; // Pile temporaire pour les éléments triés.
    t_stack *temp;

    while (!is_empty(*stack_a)) {
        temp = *stack_a;
        *stack_a = (*stack_a)->next;

        while (!is_empty(sorted) && sorted->index < temp->index) {
            t_stack *tmp = sorted;
            sorted = sorted->next;
            tmp->next = *stack_a;
            *stack_a = tmp;
        }

        temp->next = sorted;
        sorted = temp;
    }

    *stack_a = sorted; // La pile A est maintenant triée.
}

void insert_sort_stack_b(t_stack **stack_b) {
    if (is_empty(*stack_b) || stack_size(*stack_b) == 1) {
        return; // Pas besoin de trier si B est vide ou a un seul élément.
    }

    t_stack *sorted = NULL;
    t_stack *temp;

    while (!is_empty(*stack_b)) {
        temp = *stack_b;
        *stack_b = (*stack_b)->next;
        temp->next = NULL;

        // Trouvez la position correcte pour l'élément dans la pile triée
        if (is_empty(sorted) || sorted->index > temp->index) {
            temp->next = sorted;
            sorted = temp;
        } else {
            t_stack *current = sorted;
            while (current->next != NULL && current->next->index < temp->index) {
                current = current->next;
            }
            temp->next = current->next;
            current->next = temp;
        }
    }

    *stack_b = sorted;
}




void sort_stack(t_stack **stack_a, t_stack **stack_b) {
    index_stack(stack_a); // Indexez d'abord les éléments de la pile A
    int size = stack_size(*stack_a);

    // Identifiez un pivot pour déplacer les éléments vers B
    int pivot = size / 2;

    // Tri initial - déplacez les éléments basés sur le pivot vers B 
    for (int i = 0; i < size; i++) {
        if ((*stack_a)->index >= pivot) {
            pb(stack_a, stack_b);
        } else {
            ra(stack_a);
        }
    }

	// Triez la pile A en utilisant le tri par insertion
	insert_sort_stack_a(stack_a);

    // Triez la pile B en utilisant le tri par insertion
  	insert_sort_stack_b(stack_b);

	


    // Fusion des piles A et B
    merge_stacks(stack_a, stack_b);

	
	
}





int	main(int ac, char **av)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	int check;

	stack_a = init_stack();
	stack_b = init_stack();
	parse_input_arguments(ac, av, &stack_a);



	 
	sort_stack(&stack_a, &stack_b);
	
	/*
	display_stack(stack_a);
	printf("\n");
	display_stack(stack_b);
	check = is_sorted2(stack_a);
	if (check == 1)
		printf("OK\n");
	else
		printf("KO\n");
	*/
	
	
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
