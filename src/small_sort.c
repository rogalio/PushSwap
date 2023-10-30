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

int position_of(int value, t_stack *stack_a)
{
    int i;

    i = 0;
    while (stack_a)
    {
        if (stack_a->value == value)
            return (i);
        stack_a = stack_a->next;
        i++;
    }
    return (-1);
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


// cherche le median avec find_average et le place en haut de la pile
void move_median_to_top(t_stack **stack_a) 
{
    int median;
    int position;
    int size;

    median = find_median_of_three(stack_a);
    printf("median = %d\n", median);
    position = position_of(median, *stack_a);
    size = stack_size(*stack_a);

    while (peek(*stack_a) != median)
    {
        if (position <= size / 2)
            ra(stack_a);
        else
            rra(stack_a);
    }
}




