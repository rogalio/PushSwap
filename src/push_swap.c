
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
    partition_size = partition_around_pivot(stack_a, stack_b, pivot);

    
    
    quicksort_stack(stack_b, stack_a, partition_size);
    quicksort_stack(stack_a, stack_b, size - partition_size);
    

    merge_partitions(stack_a, stack_b);
}

        int merge_b_to_a_with_sort(t_stack **stack_a, t_stack **stack_b)
        {
            int size;
            int i;
            int min;

            size = stack_size(*stack_b);
            i = 0;
            while (i < size)
            {
                min = find_min(*stack_b);
                while (peek(*stack_b) != min)
                    rb(stack_b);
                pa(stack_a, stack_b);
                i++;
            }
            return (size);
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
    {
        int pivot;
        int partition_size;

        printf("part 1 - start --------\n");
        pivot = find_optimized_median(stack_a);
        printf("pivot: %d\n", pivot);
        partition_size = partition_around_pivot(stack_a, stack_b, pivot);
        printf("partition_size: %d\n", partition_size);
        printf("stack_a: \n");
        display_stack(*stack_a);
        printf("stack_b: \n");
        display_stack(*stack_b);
        printf("part 1 - end --------\n");

        printf("part 2 - start --------\n");
        pivot = find_optimized_median(stack_a);
        printf("pivot: %d\n", pivot);
        partition_size = partition_around_pivot(stack_a, stack_b, pivot);
        printf("partition_size: %d\n", partition_size);
        printf("stack_a: \n");
        display_stack(*stack_a);
        printf("stack_b: \n");
        display_stack(*stack_b);
        printf("part 2 - end --------\n");

        printf("part 3 - start --------\n");
        pivot = find_optimized_median(stack_a);
        printf("pivot: %d\n", pivot);
        partition_size = partition_around_pivot(stack_a, stack_b, pivot);
        printf("partition_size: %d\n", partition_size);
        printf("stack_a: \n");
        display_stack(*stack_a);
        printf("stack_b: \n");
        display_stack(*stack_b);
        printf("part 3 - end --------\n");

        printf("part 4 - start --------\n");
        pivot = find_optimized_median(stack_a);
        printf("pivot: %d\n", pivot);
        partition_size = partition_around_pivot(stack_a, stack_b, pivot);
        printf("partition_size: %d\n", partition_size);
        printf("stack_a: \n");
        display_stack(*stack_a);
        printf("stack_b: \n");
        display_stack(*stack_b);
        printf("part 4 - end --------\n");

        merge_b_to_a_with_sort(stack_a, stack_b);




        //merge_partitions(stack_a, stack_b);
        (void)partition_size;

        display_stack(*stack_a);
        printf("\n");
       display_stack(*stack_b);

    }
       // quicksort_stack(stack_a, stack_b, size);
}
