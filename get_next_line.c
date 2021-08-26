/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaid <azaid@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 13:42:57 by azaid             #+#    #+#             */
/*   Updated: 2021/08/27 07:52:43 by azaid            ###   ########.fr       */
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

	i = 0;
	while (str[i] != '\0' || str[i] != '\n')
	{
		if (str[i++] == '\n')
			break ;
		i++;
	}
	str = ft_substr(str, 0, i);
	return (str);
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

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != (char)c)
	{
		if (s[i] == '\0')
			return (NULL);
		i++;
	}
	return ((char *)&s[i]);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	j;
	size_t	s_len;
	char	*result;

	j = 0;
	if (s)
	{
		s_len = ft_strlen(s);
		if (start >= s_len)
			return (ft_strdup((char *)""));
		if (len > s_len)
			len = s_len + 1 - start;
		if (len > (s_len - start))
			len = s_len - start;
		result = malloc(sizeof(char) * (len + 1));
		if (!result)
			return (NULL);
		while (s[start] && j < len)
			result[j++] = s[start++];
		result[j] = '\0';
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
	while (reader)
	{
		reader = read(fd, buffer, BUFFER_SIZE);
		if (reader == -1)
			return (NULL);
		buffer[reader] = '\0';
		if (save == NULL)
			save = ft_strdup(buffer);
		else
			ft_add_buf_to_str(&save, buffer);
		if (ft_strchr(save, '\n'))
			break ;
	}
	if(save == NULL)
		return (NULL);
	save = get_until_nl(save);
	return (save);
}
