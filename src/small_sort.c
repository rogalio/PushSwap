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

        
}