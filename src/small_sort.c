#include "../include/push_swap.h"

void sa(t_stack **stack_a)
{
    swap(stack_a);
    printf("sa\n");
}

void sb(t_stack **stack_b)
{
    swap(stack_b);
    printf("sb\n");
}

void ss(t_stack **stack_a, t_stack **stack_b)
{
    swap(stack_a);
    swap(stack_b);
    printf("ss\n");
}

void pa(t_stack **stack_a, t_stack **stack_b)
{
    push(stack_a, peek((*stack_b)));
    pop(stack_b);
    printf("pa\n");
}

void pb(t_stack **stack_a, t_stack **stack_b)
{
    push(stack_b, peek((*stack_a)));
    pop(stack_a);
    printf("pb\n");
}

void ra(t_stack **stack_a)
{
   rotate_up(stack_a);
   printf("ra\n");
}

void rb(t_stack **stack_b)
{
    rotate_up(stack_b);
    printf("rb\n");
}

void rr(t_stack **stack_a, t_stack **stack_b)
{
    rotate_up(stack_a);
    rotate_up(stack_b);
    printf("rr\n");
}

void rra(t_stack **stack_a)
{
    rotate_down(stack_a);
    printf("rra\n");
}

void rrb(t_stack **stack_b)
{
    rotate_down(stack_b);
    printf("rrb\n");
}

void rrr(t_stack **stack_a, t_stack **stack_b)
{
    rotate_down(stack_a);
    rotate_down(stack_b);
    printf("rrr\n");
}



int stack_size(t_stack *stack)
{
    int size;

    size = 0;
    while (stack)
    {
        size++;
        stack = stack->next;
    }
    return (size);
}

void sort_two(t_stack **stack_a)
{
    int a, b;

    a = peek(*stack_a);
    b = peek((*stack_a)->next);
    if (a > b)
        sa(stack_a);
}

void sort_tree(t_stack **stack_a)
{
    int a, b, c;

    a = peek(*stack_a);
    b = peek((*stack_a)->next);
    c = peek((*stack_a)->next->next);

    if (a > b && b < c && a < c)
        sa(stack_a);
    else if (a > b && b > c && a > c)
    {
        sa(stack_a);
        rra(stack_a);
    }
    else if (a > b && b < c && a > c)
        ra(stack_a);
    else if (a < b && b > c && a < c)
    {
        sa(stack_a);
        ra(stack_a);
    }
    else if (a < b && b > c && a > c)
        rra(stack_a);
}

int find_min(t_stack *stack)
{
    int min;

    min = stack->value;
    while (stack)
    {
        if (stack->value < min)
            min = stack->value;
        stack = stack->next;
    }
    return (min);
}

int get_element_at(t_stack *stack, int index)
{
    int i;

    i = 0;
    while (i < index)
    {
        stack = stack->next;
        i++;
    }
    return (stack->value);
}

int position_of(int value, t_stack **stack_a)
{
    int i;
    int size;

    i = 0;
    size = stack_size(*stack_a);
    while (i < size)
    {
        if (peek(*stack_a) == value)
            return (i);
        ra(stack_a);
        i++;
    }
    return (0);
}

int   find_median_of_three(t_stack **stack_a)
{
    int first;
    int middle;
    int last;

    first = peek(*stack_a);
    middle = get_element_at(*stack_a, stack_size(*stack_a) / 2);
    last = get_element_at(*stack_a, stack_size(*stack_a) - 1);

    if ((first > middle && first < last) || (first < middle && first > last))
        return (first);
    else if ((middle > first && middle < last) || (middle < first && middle > last))
        return (middle);
    else if ((last > first && last < middle) || (last < first && last > middle))
        return (last);
    return (0);
}

void sort_four(t_stack **stack_a, t_stack **stack_b)
{   
    int min;

    min = find_min(*stack_a);
    while (peek(*stack_a) != min)
        ra(stack_a);
    pb(stack_a, stack_b);
    sort_tree(stack_a);
    pa(stack_a, stack_b);
}
void sort_five(t_stack **stack_a, t_stack **stack_b)
{
    int min;

    min = find_min(*stack_a);
    while (peek(*stack_a) != min)
        ra(stack_a);
    pb(stack_a, stack_b);
    sort_four(stack_a, stack_b);
    pa(stack_a, stack_b);
}

void sort_pivot(t_stack **stack_a, t_stack **stack_b, int pivot)
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
}

void move_median_to_top(t_stack **stack_a) 
{
    int median = find_median_of_three(stack_a);
    printf("median = %d\n", median);
    int position = position_of(median, stack_a);
    int size = stack_size(*stack_a);
    int i = 0;

    while (i < size)
    {
        if (peek(*stack_a) == median)
            break;
        else if (position < size / 2)
            ra(stack_a);
        else
            rra(stack_a);
        i++;
    }
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

    

void partition_sort(t_stack **stack_a, t_stack **stack_b)
{

    int size = stack_size(*stack_a);
    int median = find_median_of_three(stack_a);

    //(void)stack_b;
    if (size <= 5)
    {
        sort_small(stack_a, stack_b);
        return ;
    }
  
    // Choisir un pivot et le placer en haut de la pile B
    move_median_to_top(stack_a);
    partition_around_pivot(stack_a, stack_b, median);

    // Trier les éléments plus petits et plus grands que le pivot de fqcon iterative
    int newSize = stack_size(*stack_a);
    if (newSize < size)
    {
        partition_sort(stack_a, stack_b);
        partition_sort(stack_b, stack_a);
    }
    // Fusionner les partitions triées
   // merge_partitions(stack_a, stack_b);
    
}


void sort_small(t_stack **stack_a, t_stack **stack_b)
{
    int size;


    size = stack_size(*stack_a);

    if (size == 2)
        sort_two(stack_a);
    else if (size == 3)
        sort_tree(stack_a);
    else if (size == 4)
        sort_four(stack_a, stack_b);
    else if (size == 5)
        sort_five(stack_a, stack_b);
    else if (size >= 6)
    {
        partition_sort(stack_a, stack_b);
        merge_partitions(stack_a, stack_b);
    }

        
}