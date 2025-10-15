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

#include "../../includes/ft_printf.h"

size_t	ft_strlen(const char *str);
int		flag_c(const char c);
int		flag_s(const char *s);

int	flag_c(const char c)
{
	int	ret;

	ret = write(1, &c, 1);
	return (ret);
}

int	flag_s(const char *s)
{
	int	ret;

	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	ret = write(1, s, ft_strlen(s));
	return (ret);
}
