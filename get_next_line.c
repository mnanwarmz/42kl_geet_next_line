/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaid <azaid@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 13:42:57 by azaid             #+#    #+#             */
/*   Updated: 2021/08/25 08:38:33 by azaid            ###   ########.fr       */
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
	while (str[i] != '\n' && str[i] != '\0')
	{
		temp[i] = str[i];
		i++;
	}
	temp[i] = '\n';
	return (temp);
}

char	*get_next_line(int fd)
{
	static char			buffer[BUFFER_SIZE];
	char				*save;
	int					reader;

	save = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	reader = read(fd, buffer, BUFFER_SIZE);
	while (!has_nl(save) && reader != 0)
	{
		if (reader == -1)
			return (NULL);
		buffer[reader] = '\0';
		save = ft_strjoin(save, buffer);
		reader = read(fd, buffer, BUFFER_SIZE);
	}
	save = get_until_nl(save);
	return (save);
}

int	main(void)
{
	int				fd;
	char			*str;

	fd = open("file.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("%s", str);
}
