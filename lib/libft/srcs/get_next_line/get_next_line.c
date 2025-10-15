/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isibio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 11:07:10 by isibio            #+#    #+#             */
/*   Updated: 2023/01/03 11:07:11 by isibio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*stock[1024];
	char		*ret;
	int			i;
	int			ret_read;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
		return (free(stock[fd]), stock[fd] = NULL, NULL);
	buf = ft_calloc(BUFFER_SIZE + 1, ret_read = 1);
	while (ret_read > 0)
	{
		i = 0;
		while (stock[fd] && stock[fd][i] && stock[fd][i] != '\n')
			i++;
		if (stock[fd] && stock[fd][i] == '\n' && i++)
			break ;
		ret_read = read(fd, buf, BUFFER_SIZE);
		buf[ret_read] = '\0';
		stock[fd] = ft_gnl_strjoin(stock[fd], buf);
	}
	ret = ft_gnl_substr(stock[fd], 0, i);
	if (ft_strlen(ret) == 0)
		return (free(buf), free(ret), free(stock[fd]), stock[fd] = NULL, NULL);
	stock[fd] = ft_gnl_substr(stock[fd], i, ft_strlen(stock[fd]));
	return (free(buf), ret);
}
