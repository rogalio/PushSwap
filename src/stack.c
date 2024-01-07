/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogalio <rmouchel@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:21:36 by rogalio           #+#    #+#             */
/*   Updated: 2024/01/07 13:59:10 by rogalio          ###   ########.fr       */
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


/*
int get_next_line(int fd, char **line)
{
    char buf[2];
    char *tmp;
    int ret;

    if (!line || fd < 0 || read(fd, buf, 0) < 0)
        return (-1);
    *line = ft_strdup("");
    tmp = ft_strdup("");
    while ((ret = read(fd, buf, 1)) > 0 && buf[0] != '\n')
    {
        buf[ret] = '\0';
        tmp = ft_strjoin(*line, buf);
        free(*line);
        *line = tmp;
    }
    if (ret == 0 && (*line)[0] == '\0')
    {
        free(*line);
        *line = NULL;
    }
    return (ret);
}
*/



int get_next_line(int fd, char **line)
{
    char buf[2];
    char *tmp;
    int ret;

    if (!line || fd < 0 || read(fd, buf, 0) < 0)
        return (-1);
    *line = ft_strdup("");
    if (!*line)
        return (-1);
    while ((ret = read(fd, buf, 1)) > 0 && buf[0] != '\n')
    {
        buf[ret] = '\0';
        tmp = ft_strjoin(*line, buf);
        if (!tmp)
        {
            free(*line);
            return (-1);
        }
        free(*line);
        *line = tmp;
    }
    if (ret == 0 && (*line)[0] == '\0')
    {
        free(*line);
        *line = NULL;
    }
    return (ret);
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



