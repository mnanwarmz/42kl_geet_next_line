/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaid <azaid@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 13:45:34 by azaid             #+#    #+#             */
/*   Updated: 2021/08/26 16:07:57 by azaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char				*get_next_line(int fd);
int					has_nl(char *str);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_strdup(char *src);
void				ft_add_buf_to_str(char **str, void *buf);
char				*ft_strdel(char **adr_str);
char				*ft_strchr(const char *s, int c);
size_t				ft_strlen(char *str);
#endif
