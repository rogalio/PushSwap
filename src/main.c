/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouchel <rmouchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:00:41 by rmouchel          #+#    #+#             */
/*   Updated: 2023/12/04 17:08:55 by rmouchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int main(int ac, char **av)
{
    t_stack *stack_a;
    t_stack *stack_b;

    stack_a = init_stack();
    stack_b = init_stack();

    parse_input_arguments(ac, av, &stack_a);
    sort_small(&stack_a, &stack_b);
    free_stack(&stack_a);
    free_stack(&stack_b);
    return 0;
}
