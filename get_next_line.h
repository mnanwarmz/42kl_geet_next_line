/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaid <azaid@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 13:45:34 by azaid             #+#    #+#             */
/*   Updated: 2021/08/20 06:54:00 by azaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char				*get_next_line(int fd);
int					has_nl(char *str);
char				*ft_strjoin(char *s1, char *s2);
size_t				ft_strlen(char *str);
#endif
