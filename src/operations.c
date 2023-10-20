#include "../include/push_swap.h"

bool add_value_to_stack(t_stack **stack, int value)
{
    t_stack *new;
    t_stack *current;

    new = malloc(sizeof(t_stack));
    if (!new)
        return (false);
    new->value = value;
    new->next = NULL;

    // Si la pile est vide
    if (!*stack) 
    {
        *stack = new;
    }
    else 
    {
        // Sinon, trouver la fin de la pile
        current = *stack;
        while (current->next)
            current = current->next;

        // Ajouter le nouvel élément à la fin
        current->next = new;
    }
    return (true);
}

bool push(t_stack **stack, int value)
{
    t_stack *new;

    new = malloc(sizeof(t_stack));
    if (!new)
        return (false);
    new->value = value;
    new->next = *stack;
    *stack = new;
    return (true);
}

bool pop(t_stack **stack)
{
    t_stack *tmp;

    if (!*stack)
        return (false);
    tmp = *stack;
    *stack = (*stack)->next;
    free(tmp);
    return (true);
}

bool swap(t_stack **stack)
{
    t_stack *tmp;

    if (!*stack || !(*stack)->next)
        return (false);
    tmp = (*stack)->next;
    (*stack)->next = tmp->next;
    tmp->next = *stack;
    *stack = tmp;
    return (true);
}

int peek(t_stack *stack)
{
    if (!stack)
        return (0);
    return (stack->value);
}

void display_stack(t_stack *stack)
{
    while (stack)
    {
        printf("%d\n", stack->value);
        stack = stack->next;
    }
}

bool rotate_up(t_stack **stack)
{
    t_stack *tmp;
    t_stack *last;

    if (!*stack || !(*stack)->next)
        return (false);
    tmp = *stack;
    last = *stack;
    while (last->next)
        last = last->next;
    *stack = tmp->next;
    tmp->next = NULL;
    last->next = tmp;
    return (true);
}

bool rotate_down(t_stack **stack)
{
    t_stack *tmp;
    t_stack *last;

    if (!*stack || !(*stack)->next)
        return (false);
    tmp = *stack;
    while (tmp->next->next)
        tmp = tmp->next;
    last = tmp->next;
    tmp->next = NULL;
    last->next = *stack;
    *stack = last;
    return (true);
}

// pas encore utiliser

bool is_empty(t_stack *stack)
{
    return (!stack);
}

bool is_sorted(t_stack *stack)
{
    while (stack && stack->next)
    {
        if (stack->value > stack->next->value)
            return (false);
        stack = stack->next;
    }
    return (true);
}