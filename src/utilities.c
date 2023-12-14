/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogalio <rmouchel@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:58:45 by rogalio           #+#    #+#             */
/*   Updated: 2023/12/14 18:21:16 by rmouchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*init_stack(void)
{
	return (NULL);
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

void	free_split(char **tab)
{
	char	**temp;

	temp = tab;
	if (!tab)
		return ;
	while (*tab)
	{
		free(*tab);
		tab++;
	}
	free(temp);
}

int	sort_array(int *array, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] > array[j])
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	handle_error(char **tab, const char *message)
{
	free_split(tab);
	printf("%s\n", message);
	exit(1);
}

int	free_stack(t_stack **stack)
{
	t_stack	*temp;

	if (!stack)
		return (0);
	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
	return (1);
}
