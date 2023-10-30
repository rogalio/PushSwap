#include "../include/push_swap.h"

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

    pivot = find_median_of_three(stack_a);
    partition_size = partition_around_pivot(stack_a, stack_b, pivot);

    quicksort_stack(stack_b, stack_a, partition_size); // Notez que nous échangeons ici stack_a et stack_b
    quicksort_stack(stack_a, stack_b, size - partition_size);

    merge_partitions(stack_a, stack_b);
}

void sort_small(t_stack **stack_a, t_stack **stack_b)
{
    int size;

    size = stack_size(*stack_a);

    if (size <= 2)
        sort_two(stack_a);
    else if (size == 3)
        sort_tree(stack_a);
    else if (size == 4)
        sort_four(stack_a, stack_b);
    else if (size == 5)
        sort_five(stack_a, stack_b);
    else
        quicksort_stack(stack_a, stack_b, size);
}



