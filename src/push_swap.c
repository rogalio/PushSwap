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
        if (peek(*stack_a) < pivot)
            pb(stack_a, stack_b);
        else
            ra(stack_a);
        i++;
    }
    return (size - stack_size(*stack_a));
}

void merge_partitions(t_stack **stack_a, t_stack **stack_b)
{
    while (*stack_b)
    {
        rrb(stack_b);
        pa(stack_a, stack_b);
    }
}

void quicksort_stack(t_stack **stack_a, t_stack **stack_b, int size)
{
    int pivot;
    int partition_size;

    if (size <= 1 || is_sorted(*stack_a))
        return;

    if (size <= 5)
    {
        sort_small(stack_a, stack_b);
        return;
    }

    pivot = find_optimized_median(stack_a);
    printf("pivot: %d\n", pivot);
    partition_size = partition_around_pivot(stack_a, stack_b, pivot);

    
    
    quicksort_stack(stack_b, stack_a, partition_size);
    quicksort_stack(stack_a, stack_b, size - partition_size);
    

    merge_partitions(stack_a, stack_b);
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
        quicksort_stack(stack_a, stack_b, size);
}