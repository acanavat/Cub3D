/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isibio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 17:56:58 by isibio            #+#    #+#             */
/*   Updated: 2022/12/01 17:56:59 by isibio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_fprintf.h"

int	fp_check(int fd, const char flag, va_list args)
{
	int	j;

	j = 0;
	if (flag == 'c')
		j += fp_flag_c(fd, va_arg(args, int));
	else if (flag == 's')
		j += fp_flag_s(fd, va_arg(args, char *));
	else if (flag == 'p')
		j += fp_flag_p(fd, va_arg(args, unsigned long long));
	else if (flag == 'd')
		j += fp_flag_d(fd, va_arg(args, int));
	else if (flag == 'i')
		j += fp_flag_i(fd, va_arg(args, int));
	else if (flag == 'u')
		j += fp_flag_u(fd, va_arg(args, unsigned int));
	else if (flag == 'x')
		j += fp_flag_x(fd, va_arg(args, unsigned int));
	else if (flag == 'X')
		j += fp_flag_x2(fd, va_arg(args, unsigned int));
	else if (flag == '%')
		j += write(fd, "%", 1);
	else
		j += write(fd, &flag, 1);
	return (j);
}

int	ft_fprintf(int fd, const char *s, ...)
{
	int		i;
	int		j;
	va_list	args;

	i = 0;
	j = 0;
	va_start (args, s);
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1])
		{
			j += fp_check(fd, s[i + 1], args);
			i ++;
		}
		else
		{
			write(fd, &s[i], 1);
			j++;
		}
		i++;
	}
	va_end(args);
	return (j);
}
