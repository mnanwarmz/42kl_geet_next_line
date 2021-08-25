/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaid <azaid@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 13:43:03 by azaid             #+#    #+#             */
/*   Updated: 2021/08/20 06:53:56 by azaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

int	has_nl(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	total;
	size_t	i;
	size_t	j;
	char	*result;

	i = 0;
	j = 0;
	total = ft_strlen(s1) + ft_strlen(s2) + 1;
	result = (char *)malloc(sizeof(char) * total);
	if (result)
	{
		while (s1[i])
		{
			result[i] = s1[i];
			i++;
		}
		while (s2[j])
		{
			result[i + j] = s2[j];
			j++;
		}
		result[i + j] = '\0';
		return (result);
	}
	return (NULL);
}
