/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogalio <rmouchel@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 16:33:58 by rogalio           #+#    #+#             */
/*   Updated: 2024/01/07 17:03:44 by rogalio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int read_and_join(int fd, char **line) {
    char buf[2];
    char *tmp;
    int ret;

    ret = read(fd, buf, 1);
    while (ret > 0 && buf[0] != '\n') {
        buf[ret] = '\0';
        tmp = ft_strjoin(*line, buf);
        if (!tmp) {
            free(*line);
            return (-1);
        }
        free(*line);
        *line = tmp;
        ret = read(fd, buf, 1);
    }
    return ret;
}

void handle_eof(char **line, int ret) {
    if (ret == 0 && (*line)[0] == '\0') {
        free(*line);
        *line = NULL;
    }
}

void is_sorted2(t_stack *stack_a)
{
	t_stack	*current;

	current = stack_a;
	while (current->next)
	{
		if (current->value > current->next->value)
			return ;
		current = current->next;
	}
	free_stack(&stack_a);
    write(1, "OK\n", 3);
	exit(EXIT_SUCCESS);
}

void    handle_error_bonus2(char **tab, t_stack **stack)
{
    if (tab)
        free_split(tab);
    if (stack && *stack)
        free_stack(stack);
    free_stack(stack);
    write(2, "Error\n", 6);
    exit(1);
}