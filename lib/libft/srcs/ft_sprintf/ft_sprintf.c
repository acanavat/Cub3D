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

#include "../../includes/ft_sprintf.h"

static char	*handle_flag_f(double number_flag_f)
{
	if (!number_flag_f)
		return (ft_ctos('0'));
	else
		return (fts_flag_f(number_flag_f));
}

static char	*check_flags_nu(const char flag, va_list args)
{
	char	*to_return;

	to_return = ft_ctos('\0');
	if (flag == 'p')
		to_return = ft_freejoin(to_return,
				fts_flag_p(va_arg(args, unsigned long long)));
	else if (flag == 'd')
		to_return = ft_freejoin(to_return, fts_flag_d(va_arg(args, int)));
	else if (flag == 'i')
		to_return = ft_freejoin(to_return, fts_flag_i(va_arg(args, int)));
	else if (flag == 'u')
		to_return = ft_freejoin(to_return,
				fts_flag_u(va_arg(args, unsigned int)));
	else if (flag == 'x')
		to_return = ft_freejoin(to_return,
				fts_flag_x(va_arg(args, unsigned int)));
	else if (flag == 'X')
		to_return = ft_freejoin(to_return,
				fts_flag_x2(va_arg(args, unsigned int)));
	else if (flag == 'f')
		to_return = ft_freejoin(to_return,
				handle_flag_f(va_arg(args, double)));
	return (to_return);
}

static char	*check_flags_str(const char flag, va_list args)
{
	char	*to_return;

	to_return = ft_ctos('\0');
	if (flag == 'c')
		to_return = ft_freejoin(
				to_return, ft_ctos(fts_flag_c(va_arg(args, int))));
	else if (flag == 's')
		to_return = ft_freejoin(to_return, fts_flag_s(va_arg(args, char *)));
	else if (flag == '%')
		to_return = ft_freejoin(to_return, ft_ctos('%'));
	return (to_return);
}

static char	*check(const char flag, va_list args)
{
	char	*to_return;

	to_return = ft_ctos('\0');
	to_return = ft_freejoin(to_return, check_flags_nu(flag, args));
	to_return = ft_freejoin(to_return, check_flags_str(flag, args));
	if (!ft_strlen(to_return))
	{
		free(to_return);
		to_return = ft_freejoin(ft_ctos('%'), ft_ctos(flag));
	}
	return (to_return);
}

char	*ft_sprintf(const char *s, ...)
{
	va_list	args;
	int		i;
	char	*to_return;

	i = 0;
	to_return = ft_ctos('\0');
	va_start (args, s);
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1])
		{
			to_return = ft_freejoin(to_return, check(s[i + 1], args));
			i++;
		}
		else
			to_return = ft_freejoin(to_return, ft_ctos(s[i]));
		i++;
	}
	va_end(args);
	return (to_return);
}
