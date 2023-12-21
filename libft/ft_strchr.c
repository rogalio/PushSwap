/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogalio <rmouchel@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:16:41 by rmouchel          #+#    #+#             */
/*   Updated: 2023/12/21 20:14:34 by rogalio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	*ptr;
	size_t	i;

	ptr = (char *) str;
	i = 0;
	while (ptr[i])
	{
		if (ptr[i] == (char) c)
			return (&ptr[i]);
		i++;
	}
	if (ptr[i] == (char) c)
		return (&ptr[i]);
	return (NULL);
}
