/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaid <azaid@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 13:43:03 by azaid             #+#    #+#             */
/*   Updated: 2021/08/29 06:46:32 by azaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*new;
	size_t	i;

	i = 0;
	new = (char *)malloc(sizeof(char) * nmemb * size);
	if (!new)
		return (NULL);
	while (i < nmemb * size)
	{
		new[i] = 0;
		i++;
	}
	return (new);
}

char	*ft_strdup(char *src)
{
	char	*result;
	int		i;

	result = (char *)malloc(ft_strlen(src) * sizeof(char) + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		result[i] = src[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

void	ft_add_buf_to_str(char **str, void *buf)
{
	char	*tmp;

	tmp = ft_strjoin(*str, buf);
	ft_strdel(str);
	*str = tmp;
	return ;
}

char	*ft_strdel(char **adr_str)
{
	if (adr_str != NULL && *adr_str != NULL)
	{
		free(*adr_str);
		*adr_str = NULL;
	}
	return (NULL);
}

size_t	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}
