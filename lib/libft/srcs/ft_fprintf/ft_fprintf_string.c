/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isibio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:49:58 by isibio            #+#    #+#             */
/*   Updated: 2022/12/07 15:49:59 by isibio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_fprintf.h"

size_t	ft_strlen(const char *str);
int		fp_flag_c(int fd, const char c);
int		fp_flag_s(int fd, const char *s);

int	fp_flag_c(int fd, const char c)
{
	int	ret;

	ret = write(fd, &c, 1);
	return (ret);
}

int	fp_flag_s(int fd, const char *s)
{
	int	ret;

	if (!s)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	ret = write(fd, s, ft_strlen(s));
	return (ret);
}
