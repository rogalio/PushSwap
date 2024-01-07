/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogalio <rmouchel@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:21:36 by rogalio           #+#    #+#             */
/*   Updated: 2024/01/07 17:52:59 by rogalio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_position(int *array, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (array[i] == value)
			return (i + 1);
		i++;
	}
	return (0);
}


int get_next_line(int fd, char **line) {
    int ret;

    if (!line || fd < 0)
        return (-1);
    *line = ft_strdup("");
    if (!*line)
        return (-1);

    ret = read_and_join(fd, line);
    handle_eof(line, ret);
    return ret;
}








void	free_and_exit(t_stack **stack, char **tab)
{
	free_stack(stack);
	free_split(tab);
	write(1, "Error\n", 6);
	exit(1);
}

bool	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}
int ft_strcmp(char *s1, char *s2)
{
    int i;

    i = 0;
    while (s1[i])
    {
        if (s1[i] != s2[i])
            return (1);
        i++;
    }
    if (s2[i])
        return (1);
    return (0);
}



