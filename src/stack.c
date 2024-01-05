/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogalio <rmouchel@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:21:36 by rogalio           #+#    #+#             */
/*   Updated: 2024/01/05 18:34:27 by rogalio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int get_position(int *array, int size, int value)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (array[i] == value)
			return (i + 1);
		i++;
	}
	return (0);
}


