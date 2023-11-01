 #include "../include/push_swap.h"

int main(int ac, char **av)
{
    t_stack *stack_a;
    t_stack *stack_b;
 
    stack_a = init_stack();
    stack_b = init_stack();

    parse_input_arguments(ac, av, &stack_a);

   sort_small(&stack_a, &stack_b);
   
   //display_stack(stack_a);
   //printf("\n");
   //display_stack(stack_b);

   
    return 0;
}