/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaid <azaid@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 13:45:34 by azaid             #+#    #+#             */
/*   Updated: 2021/08/29 06:41:13 by azaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char				*get_next_line(int fd);
void				*ft_calloc(size_t count, size_t size);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_strdup(char *src);
void				ft_add_buf_to_str(char **str, void *buf);
char				*ft_strdel(char **adr_str);
char				*ft_strchr(const char *s, int c);
char				*ft_substr(char const *s, unsigned int start, size_t len);
size_t				ft_strlen(char const *str);
#endif
