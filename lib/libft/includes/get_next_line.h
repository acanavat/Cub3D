/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isibio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 11:17:45 by isibio            #+#    #+#             */
/*   Updated: 2023/01/03 11:18:24 by isibio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft.h"

char	*get_next_line(int fd);
char	*ft_gnl_strjoin(char *s1, char *s2);
char	*ft_gnl_substr(char *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
void	*ft_calloc(size_t eCount, size_t eSize);
void	ft_bzero(void *s, size_t n);

#endif