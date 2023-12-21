/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogalio <rmouchel@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:26:23 by rmouchel          #+#    #+#             */
/*   Updated: 2023/12/21 20:08:39 by rogalio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = (char *)str;
	while (ptr[i])
		i++;
	while (i > 0)
	{
		if (ptr[i] == (char)c)
			return (&ptr[i]);
		i--;
	}
	if (ptr[i] == (char)c)
		return (&ptr[i]);
	return (NULL);
}
