#include "../include/push_swap.h"

int find_optimized_median(t_stack **stack_a) 
{
    int size;
    int i;
    int median;
    int *array;

    size = stack_size(*stack_a);
    array = malloc(sizeof(int) * size);
    if (!array)
        handle_error(0, "malloc failed");
    i = 0;
    while (i < size)
    {
        array[i] = peek(*stack_a);
        ra(stack_a);
        i++;
    }
    sort_array(array, size);
    median = array[size / 2];
    free(array);
    return (median);

 
}

int partition_around_pivot(t_stack **stack_a, t_stack **stack_b, int pivot)
{
    int size;
    int i;

    size = stack_size(*stack_a);
    i = 0;
    while (i < size)
    {
        // jai ajouter le = pour test
        if (peek(*stack_a) <= pivot)
            pb(stack_a, stack_b);
        else
            ra(stack_a);
        i++;
    }
    return (size - stack_size(*stack_a));
}

int sort_b_and_push_to_a(t_stack **stack_a, t_stack **stack_b)
{
    int max;
    int size; 
    int i; 

    size = stack_size(*stack_b);
    i = 0;

    // Iterate for each element in stack_b
    while (i < size)
    {
        // Find the maximum value in stack_b
        max = find_max(*stack_b);
        // Rotate stack_b until the maximum value is on top
        while (peek(*stack_b) != max)
            rb(stack_b);
        // Push the maximum value from stack_b to stack_a
        pa(stack_a, stack_b);
        i++;
    }
    return (size);
}

void quicksort_stack(t_stack **stack_a, t_stack **stack_b)
{
    int pivot;
    // Continue until stack_a is empty
    while (stack_size(*stack_a) > 0) 
    {   
        // Determine an optimized pivot from stack_a
        // moving elements less than the pivot to stack_b
        pivot = find_optimized_median(stack_a);
        partition_around_pivot(stack_a, stack_b, pivot);
    }
    // Sort elements in stack_b and push them back to stack_a in correct order
    sort_b_and_push_to_a(stack_a, stack_b);
}


void sort_small(t_stack **stack_a, t_stack **stack_b)
{
    int size;

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