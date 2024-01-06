/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogalio <rmouchel@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:45:52 by rogalio           #+#    #+#             */
/*   Updated: 2024/01/06 11:42:09 by rogalio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"



int  check_if_sorted(t_stack *stack_a)
{
    t_stack *current;

    current = stack_a;
    while (current->next)
    {
        if (current->value > current->next->value)
            return (1);
        current = current->next;
    }
    return (0);
}

int execute_operation(char *line, t_stack **stack_a, t_stack **stack_b)
{
    if (ft_strcmp(line, "sa") == 0)
        swap(stack_a);
    else if (ft_strcmp(line, "sb") == 0)
        swap(stack_b);
    else if (ft_strcmp(line, "ss") == 0)
        ss1(stack_a, stack_b);
    else if (ft_strcmp(line, "pa") == 0)
        pa1(stack_a, stack_b);
    else if (ft_strcmp(line, "pb") == 0)
        pb1(stack_a, stack_b);
    else if (ft_strcmp(line, "ra") == 0)
        rotate_up(stack_a);
    else if (ft_strcmp(line, "rb") == 0)
        rotate_up(stack_b);
    else if (ft_strcmp(line, "rr") == 0)
        rr1(stack_a, stack_b);
    else if (ft_strcmp(line, "rra") == 0)
        rotate_down(stack_a);
    else if (ft_strcmp(line, "rrb") == 0)
        rotate_down(stack_b);
    else if (ft_strcmp(line, "rrr") == 0)
        rrr1(stack_a, stack_b);
    else
        return (0);
    return (1);
}

int process_input_commands(t_stack **stack_a, t_stack **stack_b)
{
    char *line;

    while (get_next_line(0, &line) > 0)
    {
        if (!execute_operation(line, stack_a, stack_b))
        {
            free(line);
            return (0);
        }
        free(line);
    }
    return (1);
}

void check_sort_and_show_result(t_stack **stack_a, t_stack **stack_b)
{
    int is_sorted;

    is_sorted = check_if_sorted(*stack_a);
    if (is_sorted == 0 && stack_size(*stack_b) == 0)
        write(1, "OK\n", 3);
    else if (is_sorted == false && stack_size(*stack_b) == 0)
        write(1, "KO\n", 3);
    else
        write(1, "KO\n", 3);
}


int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;

    stack_a = init_stack();
    stack_b = init_stack();
    parse_input_arguments2(argc, argv, &stack_a);
    index_stack(stack_a);
    process_input_commands(&stack_a, &stack_b);
    check_sort_and_show_result(&stack_a, &stack_b);
    free_stack(&stack_a);
    free_stack(&stack_b);
    return (0);
}