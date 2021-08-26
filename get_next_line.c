/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaid <azaid@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 13:42:57 by azaid             #+#    #+#             */
/*   Updated: 2021/08/26 15:46:54 by azaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

char	*get_until_nl(char *str)
{
	int		i;
	char	*temp;

	i = 0;
	temp = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	while (str[i] != '\0')
	{
		temp[i] = str[i];
		if (str[i] == '\n')
			break ;
		i++;
	}
	return (temp);
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

char	*get_next_line(int fd)
{
	static char			*save;
	char				buffer[BUFFER_SIZE + 1];
	int					reader;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	reader = 1;
	while (!has_nl(save) && reader != 0)
	{
		if (reader == -1)
			return (NULL);
		buffer[reader] = '\0';
		if (save == NULL)
			save = ft_strdup(buffer);
		else
			ft_add_buf_to_str(&save, buffer);
		reader = read(fd, buffer, BUFFER_SIZE);
	}
	save = get_until_nl(save);
	return (save);
}
