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

#include "../../includes/ft_printf.h"

int	check(const char flag, va_list args)
{
	int	j;

	j = 0;
	if (flag == 'c')
		j += flag_c(va_arg(args, int));
	else if (flag == 's')
		j += flag_s(va_arg(args, char *));
	else if (flag == 'p')
		j += flag_p(va_arg(args, unsigned long long));
	else if (flag == 'd')
		j += flag_d(va_arg(args, int));
	else if (flag == 'i')
		j += flag_i(va_arg(args, int));
	else if (flag == 'u')
		j += flag_u(va_arg(args, unsigned int));
	else if (flag == 'x')
		j += flag_x(va_arg(args, unsigned int));
	else if (flag == 'X')
		j += flag_x2(va_arg(args, unsigned int));
	else if (flag == '%')
		j += write(1, "%", 1);
	else
		j += write(1, &flag, 1);
	return (j);
}

int	ft_printf(const char *s, ...)
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
			j += check(s[i + 1], args);
			i ++;
		}
		else
		{
			write(1, &s[i], 1);
			j++;
		}
		i++;
	}
	va_end(args);
	return (j);
}
