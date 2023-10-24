 #include "../include/push_swap.h"

int main(int ac, char **av)
{
    t_stack *stack_a;
    t_stack *stack_b;

    (void)stack_b;  
    stack_a = init_stack();
    stack_b = init_stack();

    parse_input_arguments(ac, av, &stack_a);

    //printf("is_sorted(stack_a) = %d\n", is_sorted(stack_a));
   // printf(" find_median_of_three(stack_a) = %d\n", find_median_of_three(&stack_a));
    //move_median_to_top(&stack_a);
    //partition_around_pivot(&stack_a, &stack_b, find_median_of_three(&stack_a));
    
    //sort_small(&stack_a, &stack_b);
    partition_sort(&stack_a, &stack_b);
    //merge_partitions(&stack_a, &stack_b);
    /*
        printf("\n");
    display_stack(stack_b);
    printf("\n");
    */
   display_stack(stack_a);
   printf("\n");
   display_stack(stack_b);

   
    return 0;
}