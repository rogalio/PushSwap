/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogalio <rmouchel@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 18:23:42 by rmouchel          #+#    #+#             */
/*   Updated: 2023/12/21 20:13:54 by rogalio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_numlen(int n)
{
	int				len;
	unsigned int	un;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len++;
		un = (unsigned int)(-n);
	}
	else
		un = (unsigned int)n;
	while (un > 0)
	{
		un /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*res;
	int				len;
	unsigned int	un;

	len = ft_numlen(n);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (n == 0)
		res[0] = '0';
	if (n < 0)
	{
		res[0] = '-';
		un = (unsigned int)(-n);
	}
	else
		un = (unsigned int)n;
	while (un > 0)
	{
		res[--len] = (un % 10) + '0';
		un /= 10;
	}
	return (res);
}
